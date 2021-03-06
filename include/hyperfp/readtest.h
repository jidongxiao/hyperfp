/*
 * readtest.h: msr read related definitions
 * Copyright (c) 2018, Jidong Xiao (jidong.xiao@gmail.com).
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 *
 *
 */

#ifndef __READTEST_H
#define __READTEST_H

extern int test_msr_efer();
extern int test_msr_star();
extern int test_msr_lstar();
extern int test_msr_cstar();
extern int test_msr_syscall_mask();
extern int test_msr_fs_base();
extern int test_msr_gs_base();
extern int test_msr_kernel_gs_base();
extern int test_msr_tsc_aux();

extern int test_msr_ppin_ctl();
extern int test_msr_ppin();

extern int test_msr_ia32_perfctr0();
extern int test_msr_ia32_perfctr1();
extern int test_msr_fsb_freq();
extern int test_msr_platform_info();
extern int test_msr_platform_info_cpuid_fault_bit();
extern int test_msr_platform_info_cpuid_fault();


extern int test_msr_ia32_bbl_cr_ctl();
extern int test_msr_ia32_bbl_cr_ctl3();

extern int test_msr_ia32_sysenter_cs();
extern int test_msr_ia32_sysenter_esp();
extern int test_msr_ia32_sysenter_eip();

extern int test_msr_ia32_mcg_cap();
extern int test_msr_ia32_mcg_status();
extern int test_msr_ia32_mcg_ctl();
extern int test_msr_ia32_mcg_ext_ctl();

extern int test_msr_offcore_rsp_0();
extern int test_msr_offcore_rsp_1();
extern int test_msr_turbo_ratio_limit();
extern int test_msr_turbo_ratio_limit1();
extern int test_msr_turbo_ratio_limit2();


extern int test_msr_ia32_pebs_enable();
extern int test_msr_ia32_ds_area();
extern int test_msr_ia32_perf_capabilities();
extern int test_msr_pebs_ld_lat_threshold();


extern int test_msr_k8_tseg_addr();
extern int test_msr_k8_tseg_mask();

extern int test_msr_amd64_dc_cfg();

extern int test_msr_k7_evntsel1();
extern int test_msr_k7_evntsel2();
extern int test_msr_k7_evntsel3();
extern int test_msr_k7_perfctr1();
extern int test_msr_k7_perfctr2();
extern int test_msr_k7_perfctr3();

extern int test_msr_ia32_feature_control();

extern int test_msr_ia32_smm_monitor_ctl();
extern int test_msr_ia32_smbase();

extern int test_msr_ia32_vmx_basic();
extern int test_msr_ia32_vmx_pinbased_ctls();
extern int test_msr_ia32_vmx_procbased_ctls();
extern int test_msr_ia32_vmx_exit_ctls();
extern int test_msr_ia32_vmx_entry_ctls();
extern int test_msr_ia32_vmx_misc();
extern int test_msr_ia32_vmx_cr0_fixed0();
extern int test_msr_ia32_vmx_cr0_fixed1();
extern int test_msr_ia32_vmx_cr4_fixed0();
extern int test_msr_ia32_vmx_cr4_fixed1();
extern int test_msr_ia32_vmx_vmcs_enum();
extern int test_msr_ia32_vmx_procbased_ctls2();
extern int test_msr_ia32_vmx_ept_vpid_cap();
extern int test_msr_ia32_vmx_true_pinbased_ctls();
extern int test_msr_ia32_vmx_true_procbased_ctls();
extern int test_msr_ia32_vmx_true_exit_ctls();
extern int test_msr_ia32_vmx_true_entry_ctls();
extern int test_msr_ia32_vmx_vmfunc();

extern int test_hv_x64_msr_reset();
extern int test_hv_x64_msr_vp_runtime();
extern int test_hv_x64_msr_time_ref_count();
extern int test_hv_x64_msr_tsc_frequency();
extern int test_hv_x64_msr_apic_frequency();


extern int test_hv_x64_msr_crash_p0();
extern int test_hv_x64_msr_crash_p1();
extern int test_hv_x64_msr_crash_p2();
extern int test_hv_x64_msr_crash_p3();
extern int test_hv_x64_msr_crash_p4();
extern int test_hv_x64_msr_crash_ctl();
extern int test_hv_x64_msr_crash_ctl_notify();
extern int test_hv_x64_msr_crash_params();

#endif /* readtest.h */
