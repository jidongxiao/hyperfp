/*
 * This file includes the main function of the hyperfp project.
 * Initial work by:
 *   (c) 2018 Jidong Xiao (jidong.xiao@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#include <stdio.h>
#include "hyperfp/debug.h"
#include "hyperfp/lib.h"
#include "hyperfp/msr.h"
#include "hyperfp/readtest.h"

#ifndef DEBUG
#define DEBUG 0
#endif

static int (*const kvm_msr_readable[])() = {
        [0]             = test_msr_efer,
        [1]             = test_msr_star,
        [2]             = test_msr_lstar,
        [3]             = test_msr_cstar,
        [4]             = test_msr_syscall_mask,
        [5]             = test_msr_fs_base,
        [6]             = test_msr_gs_base,
        [7]             = test_msr_kernel_gs_base,
        [8]             = test_msr_tsc_aux,
        [9]             = test_msr_ppin_ctl,
        [10]             = test_msr_ppin,
        [11]             = test_msr_ia32_perfctr0,
        [12]             = test_msr_ia32_perfctr1,
        [13]             = test_msr_fsb_freq,
        [14]             = test_msr_platform_info,
        [15]             = test_msr_platform_info_cpuid_fault_bit,
        [16]             = test_msr_platform_info_cpuid_fault,

        [17]             = test_msr_ia32_bbl_cr_ctl,
        [18]             = test_msr_ia32_bbl_cr_ctl3,
        [19]             = test_msr_ia32_sysenter_cs,
        [20]             = test_msr_ia32_sysenter_esp,
        [21]             = test_msr_ia32_sysenter_eip,
        [22]             = test_msr_ia32_mcg_cap,
        [23]             = test_msr_ia32_mcg_status,
        [24]             = test_msr_ia32_mcg_ctl,
        [25]             = test_msr_ia32_mcg_ext_ctl,

        [26]             = test_msr_offcore_rsp_0,
        [27]             = test_msr_offcore_rsp_1,
        [28]             = test_msr_turbo_ratio_limit,
        [29]             = test_msr_turbo_ratio_limit1,
        [30]             = test_msr_turbo_ratio_limit2,


        [31]             = test_msr_ia32_pebs_enable,
        [32]             = test_msr_ia32_ds_area,
        [33]             = test_msr_ia32_perf_capabilities,
        [34]             = test_msr_pebs_ld_lat_threshold,


        [35]             = test_msr_k8_tseg_addr,
        [36]             = test_msr_k8_tseg_mask,
        [37]             = test_msr_amd64_dc_cfg,
        [38]             = test_msr_k7_evntsel1,
        [39]             = test_msr_k7_evntsel2,
        [40]             = test_msr_k7_evntsel3,
        [41]             = test_msr_k7_perfctr1,
        [42]             = test_msr_k7_perfctr2,
        [43]             = test_msr_k7_perfctr3,

        [44]             = test_msr_ia32_feature_control,
        [45]             = test_msr_ia32_smm_monitor_ctl,
        [46]             = test_msr_ia32_smbase,
        [47]             = test_msr_ia32_vmx_basic,
        [48]             = test_msr_ia32_vmx_pinbased_ctls,
        [49]             = test_msr_ia32_vmx_procbased_ctls,
        [50]             = test_msr_ia32_vmx_exit_ctls,
        [51]             = test_msr_ia32_vmx_entry_ctls,
        [52]             = test_msr_ia32_vmx_misc,
        [53]             = test_msr_ia32_vmx_cr0_fixed0,
        [54]             = test_msr_ia32_vmx_cr0_fixed1,
        [55]             = test_msr_ia32_vmx_cr4_fixed0,
        [56]             = test_msr_ia32_vmx_cr4_fixed1,
        [57]             = test_msr_ia32_vmx_vmcs_enum,
        [58]             = test_msr_ia32_vmx_procbased_ctls2,
        [59]             = test_msr_ia32_vmx_ept_vpid_cap,
        [60]             = test_msr_ia32_vmx_true_pinbased_ctls,
        [61]             = test_msr_ia32_vmx_true_procbased_ctls,
        [62]             = test_msr_ia32_vmx_true_exit_ctls,
        [63]             = test_msr_ia32_vmx_true_entry_ctls,
        [64]             = test_msr_ia32_vmx_vmfunc,
        [65]             = test_hv_x64_msr_reset,
        [66]             = test_hv_x64_msr_vp_runtime,
        [67]             = test_hv_x64_msr_time_ref_count,
        [68]             = test_hv_x64_msr_tsc_frequency,
        [69]             = test_hv_x64_msr_apic_frequency,
        [70]             = test_hv_x64_msr_crash_p0,
        [71]             = test_hv_x64_msr_crash_p1,
        [72]             = test_hv_x64_msr_crash_p2,
        [73]             = test_hv_x64_msr_crash_p3,
        [74]             = test_hv_x64_msr_crash_p4,
        [75]             = test_hv_x64_msr_crash_ctl,
/* FIXME: Can't compile       [46]             = test_hv_x64_msr_crash_ctl_notify, */
        [76]             = test_hv_x64_msr_crash_params
};

static const int kvm_msr_read_max =
        ARRAY_SIZE(kvm_msr_readable);

static int (*const kvm_msr_writable[])() = {
//        [MSR_IA32_MCG_STATUS]	= test_msr_ia32_mcg_status,
};

static const int kvm_msr_write_max = 1;
//        ARRAY_SIZE(kvm_msr_writable);

int main()
{

        DPRINTF("project kick-off!\n");
	int i=0;
	int readable=0;

	DPRINTF("===Starting MSR Read Test!===\n");
	for(i=0;i<kvm_msr_read_max;i++)
	{
		//Read Test MSR i;
		readable=kvm_msr_readable[i]();
		if(readable == 1)
			DPRINTF(" readable\n");
		else
			DPRINTF(" not readable\n");
			
	}

	DPRINTF("===Starting MSR Write Test!===\n");
	for(i=0;i<kvm_msr_write_max;i++)
	{
		//Write Test MSR i;
		DPRINTF("MSR xxx is writable\n");
	}

        return 0;
}

