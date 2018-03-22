/*
 * msr.h:  This file defines msr registers.
 * Copyright (c) 2018, Jidong Xiao (jidong.xiao@gmail.com)
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
#ifndef __MSR_H
#define __MSR_H

#include <inttypes.h>

/* x86-64 specific MSRs */
#define MSR_EFER		0xc0000080 /* extended feature register */
#define MSR_STAR                0xc0000081 /* legacy mode SYSCALL target */
#define MSR_LSTAR               0xc0000082 /* long mode SYSCALL target */
#define MSR_CSTAR               0xc0000083 /* compat mode SYSCALL target */
#define MSR_SYSCALL_MASK        0xc0000084 /* EFLAGS mask for syscall */
#define MSR_FS_BASE             0xc0000100 /* 64bit FS base */
#define MSR_GS_BASE             0xc0000101 /* 64bit GS base */
#define MSR_KERNEL_GS_BASE      0xc0000102 /* SwapGS GS shadow */
#define MSR_TSC_AUX             0xc0000103 /* Auxiliary TSC */

/* Intel MSRs. Some also available on other CPUs */

#define MSR_PPIN_CTL                    0x0000004e
#define MSR_PPIN                        0x0000004f

#define MSR_IA32_PERFCTR0               0x000000c1
#define MSR_IA32_PERFCTR1               0x000000c2
#define MSR_FSB_FREQ                    0x000000cd
#define MSR_PLATFORM_INFO               0x000000ce
#define MSR_PLATFORM_INFO_CPUID_FAULT_BIT       31
#define MSR_PLATFORM_INFO_CPUID_FAULT           BIT_ULL(MSR_PLATFORM_INFO_CPUID_FAULT_BIT)

#define MSR_PKG_CST_CONFIG_CONTROL      0x000000e2
#define NHM_C3_AUTO_DEMOTE              (1UL << 25)
#define NHM_C1_AUTO_DEMOTE              (1UL << 26)
#define ATM_LNC_C6_AUTO_DEMOTE          (1UL << 25)
#define SNB_C1_AUTO_UNDEMOTE            (1UL << 27)
#define SNB_C3_AUTO_UNDEMOTE            (1UL << 28)

#define MSR_MTRRcap                     0x000000fe
#define MSR_IA32_BBL_CR_CTL             0x00000119
#define MSR_IA32_BBL_CR_CTL3            0x0000011e

#define MSR_IA32_SYSENTER_CS            0x00000174
#define MSR_IA32_SYSENTER_ESP           0x00000175
#define MSR_IA32_SYSENTER_EIP           0x00000176

#define MSR_IA32_MCG_CAP                0x00000179
#define MSR_IA32_MCG_STATUS             0x0000017a
#define MSR_IA32_MCG_CTL                0x0000017b
#define MSR_IA32_MCG_EXT_CTL            0x000004d0

#define MSR_OFFCORE_RSP_0               0x000001a6
#define MSR_OFFCORE_RSP_1               0x000001a7
#define MSR_TURBO_RATIO_LIMIT           0x000001ad
#define MSR_TURBO_RATIO_LIMIT1          0x000001ae
#define MSR_TURBO_RATIO_LIMIT2          0x000001af

#define MSR_LBR_SELECT                  0x000001c8
#define MSR_LBR_TOS                     0x000001c9
#define MSR_LBR_NHM_FROM                0x00000680
#define MSR_LBR_NHM_TO                  0x000006c0
#define MSR_LBR_CORE_FROM               0x00000040
#define MSR_LBR_CORE_TO                 0x00000060

#define MSR_LBR_INFO_0                  0x00000dc0 /* ... 0xddf for _31 */



#define MSR_IA32_PEBS_ENABLE            0x000003f1
#define MSR_IA32_DS_AREA                0x00000600
#define MSR_IA32_PERF_CAPABILITIES      0x00000345
#define MSR_PEBS_LD_LAT_THRESHOLD       0x000003f6

#define MSR_K8_TSEG_ADDR                0xc0010112
#define MSR_K8_TSEG_MASK                0xc0010113

#define MSR_IA32_FEATURE_CONTROL        0x0000003a

#define MSR_IA32_SMM_MONITOR_CTL        0x0000009b
#define MSR_IA32_SMBASE                 0x0000009e

/* K7 MSRs */
#define MSR_K7_EVNTSEL0                 0xc0010000
#define MSR_K7_PERFCTR0                 0xc0010004
#define MSR_K7_EVNTSEL1                 0xc0010001
#define MSR_K7_PERFCTR1                 0xc0010005
#define MSR_K7_EVNTSEL2                 0xc0010002
#define MSR_K7_PERFCTR2                 0xc0010006
#define MSR_K7_EVNTSEL3                 0xc0010003
#define MSR_K7_PERFCTR3                 0xc0010007
#define MSR_K7_CLK_CTL                  0xc001001b
#define MSR_K7_HWCR                     0xc0010015
#define MSR_K7_FID_VID_CTL              0xc0010041
#define MSR_K7_FID_VID_STATUS           0xc0010042

#define MSR_IA32_EBL_CR_POWERON         0x0000002a 
#define MSR_IA32_PERF_STATUS		0x00000198
#define MSR_IA32_MC0_MISC		0x00000403
#define MSR_VM_HSAVE_PA			0xc0010117

/* Intel VT MSRs */
#define MSR_IA32_VMX_BASIC              0x00000480
#define MSR_IA32_VMX_PINBASED_CTLS      0x00000481
#define MSR_IA32_VMX_PROCBASED_CTLS     0x00000482
#define MSR_IA32_VMX_EXIT_CTLS          0x00000483
#define MSR_IA32_VMX_ENTRY_CTLS         0x00000484
#define MSR_IA32_VMX_MISC               0x00000485
#define MSR_IA32_VMX_CR0_FIXED0         0x00000486
#define MSR_IA32_VMX_CR0_FIXED1         0x00000487
#define MSR_IA32_VMX_CR4_FIXED0         0x00000488
#define MSR_IA32_VMX_CR4_FIXED1         0x00000489
#define MSR_IA32_VMX_VMCS_ENUM          0x0000048a
#define MSR_IA32_VMX_PROCBASED_CTLS2    0x0000048b
#define MSR_IA32_VMX_EPT_VPID_CAP       0x0000048c
#define MSR_IA32_VMX_TRUE_PINBASED_CTLS  0x0000048d
#define MSR_IA32_VMX_TRUE_PROCBASED_CTLS 0x0000048e
#define MSR_IA32_VMX_TRUE_EXIT_CTLS      0x0000048f
#define MSR_IA32_VMX_TRUE_ENTRY_CTLS     0x00000490
#define MSR_IA32_VMX_VMFUNC             0x00000491

#define MSR_IA32_MC0_CTL          	0x00000400	// Clear bit 10 of this register is not allowed until 2.6.34
							// Writing 0x8 to it is not supported until kernel 3.4
#define MSR_EBC_FREQUENCY_ID            0x0000002c	// Not readable until kernel 2.6.37
#define MSR_IA32_BBL_CR_CTL3            0x0000011e	// Not readable until kernel 2.6.39

#define MSR_IA32_UCODE_REV              0x0000008b	// Not readable until kernel 3.2
#define MSR_IA32_TSC_ADJUST             0x0000003b	// Not readable until kernel 3.8
#define MSR_AMD64_BU_CFG2         	0xc001102a	// Not readable until kernel 3.9

#define MSR_IA32_VMX_ENTRY_CTLS         0x00000484	// Since kernel 3.10, when nested=1, bit 0-8, bit 12 of this register should be 1.
							// Before 3.10, this might be some other value.
#define VM_ENTRY_ALWAYSON_WITHOUT_TRUE_MSR	0x000011ff	// i.e., bit 0-8 and bit 12 is 1.

#define MSR_IA32_FEATURE_CONTROL        0x0000003a	// When nested=1, writable even if lock bit is set, fixed in kernel 3.12
							// When nested=0, readable, but is is not supposed to be readable when nested=0, fixed in kernel 3.12
#define FEATURE_CONTROL_LOCKED          (1<<0)

#define MSR_IA32_APICBASE         	0x0000001b	// Reserve bits of this register is not writable since kernel 3.14.

/* PMUv2 related MSR */
/* Intel Core-based CPU performance counters */
#define MSR_CORE_PERF_FIXED_CTR0        0x00000309
#define MSR_CORE_PERF_FIXED_CTR1        0x0000030a
#define MSR_CORE_PERF_FIXED_CTR2        0x0000030b
#define MSR_CORE_PERF_FIXED_CTR_CTRL    0x0000038d
#define MSR_CORE_PERF_GLOBAL_STATUS     0x0000038e
#define MSR_CORE_PERF_GLOBAL_CTRL       0x0000038f
#define MSR_CORE_PERF_GLOBAL_OVF_CTRL   0x00000390

/* Custom MSRs */
#define MSR_KVM_API_MAGIC		0x87655678
#define MSR_KVM_WALL_CLOCK_NEW		0x4b564d00
#define MSR_KVM_SYSTEM_TIME_NEW		0x4b564d01
#define MSR_KVM_ASYNC_PF_EN		0x4b564d02
#define MSR_KVM_STEAL_TIME		0x4b564d03
#define HV_X64_MSR_APIC_ASSIST_PAGE     0x40000073
#define MSR_P6_PERFCTR0			0x000000c1	// Used for detecting pmuv2
#define MSR_KVM_PV_EOI_EN		0x4b564d04	// Used for detecting paravirtualized EOI enable.
#define MSR_IA32_VMX_PINBASED_CTLS      0x00000481	// Used for detecting preemption timer.
#define MSR_IA32_VMX_PROCBASED_CTLS2    0x0000048b	// Used for detecting nested ept.
#define MSR_IA32_VMX_EPT_VPID_CAP       0x0000048c	// Used for detecting nested ept 2MB page.


/* MSR used to reset the guest OS. */
#define HV_X64_MSR_RESET                        0x40000003

/* MSR used to provide vcpu runtime in 100ns units */
#define HV_X64_MSR_VP_RUNTIME                   0x40000010

/* MSR used to read the per-partition time reference counter */
#define HV_X64_MSR_TIME_REF_COUNT	0x40000020

/* MSR used to retrieve the TSC frequency */
#define HV_X64_MSR_TSC_FREQUENCY                0x40000022

/* MSR used to retrieve the local APIC timer frequency */
#define HV_X64_MSR_APIC_FREQUENCY               0x40000023

/* Hyper-V guest crash notification MSR's */
#define HV_X64_MSR_CRASH_P0                     0x40000100
#define HV_X64_MSR_CRASH_P1                     0x40000101
#define HV_X64_MSR_CRASH_P2                     0x40000102
#define HV_X64_MSR_CRASH_P3                     0x40000103
#define HV_X64_MSR_CRASH_P4                     0x40000104
#define HV_X64_MSR_CRASH_CTL                    0x40000105
#define HV_X64_MSR_CRASH_CTL_NOTIFY             (1ULL << 63)
#define HV_X64_MSR_CRASH_PARAMS         \
                (1 + (HV_X64_MSR_CRASH_P4 - HV_X64_MSR_CRASH_P0))

uint64_t rdmsr_on_cpu(uint32_t reg, int cpu);
void wrmsr_on_cpu(uint32_t reg, int cpu, uint64_t data);

#endif /* msr.h */
