/*
 * This file implements all read test cases.
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
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include "hyperfp/debug.h"
#include "hyperfp/msr.h"
#include "hyperfp/lib.h"

// This function use fork to create a child process. The child process tries to read MSR_EFER.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_efer()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_EFER,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_EFER is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1; // why would the code come to here??
}

// This function use fork to create a child process. The child process tries to read MSR_STAR.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_star()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_STAR,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_STAR is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1; // why would the code come to here??
}

// This function use fork to create a child process. The child process tries to read MSR_LSTAR.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_lstar()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_LSTAR,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_LSTAR is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1; // why would the code come to here??
}

// This function use fork to create a child process. The child process tries to read MSR_CSTAR.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_cstar()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_CSTAR,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_CSTAR is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1; // why would the code come to here??
}

// This function use fork to create a child process. The child process tries to read MSR_SYSCALL_MASK.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_syscall_mask()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_SYSCALL_MASK,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_SYSCALL_MASK is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1; // why would the code come to here??
}

// This function use fork to create a child process. The child process tries to read MSR_FS_BASE.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_fs_base()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_FS_BASE,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_FS_BASE is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_GS_BASE.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_gs_base()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_GS_BASE,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_GS_BASE is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_KERNEL_GS_BASE.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_kernel_gs_base()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_KERNEL_GS_BASE,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_KERNEL_GS_BASE is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_TSC_AUX.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_tsc_aux()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_TSC_AUX,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_TSC_AUX is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_PPIN_CTL.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ppin_ctl()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_PPIN_CTL,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_PPIN_CTL is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_PPIN.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ppin()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_PPIN,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_PPIN is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_PERFCTR0.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_perfctr0()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_PERFCTR0,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_PERFCTR0 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_PERFCTR1.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_perfctr1()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_PERFCTR1,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_PERFCTR1 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_FSB_FREQ.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_fsb_freq()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_FSB_FREQ,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_FSB_FREQ is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_PLATFORM_INFO.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_platform_info()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_PLATFORM_INFO,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_PLATFORM_INFO is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_PLATFORM_INFO_CPUID_FAULT_BIT.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_platform_info_cpuid_fault_bit()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_PLATFORM_INFO_CPUID_FAULT_BIT,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_PLATFORM_INFO_CPUID_FAULT_BIT is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_PLATFORM_INFO_CPUID_FAULT.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_platform_info_cpuid_fault()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_PLATFORM_INFO_CPUID_FAULT,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_PLATFORM_INFO_CPUID_FAULT is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_BBL_CR_CTL
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_bbl_cr_ctl()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_BBL_CR_CTL,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_BBL_CR_CTL is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_BBL_CR_CTL3
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_bbl_cr_ctl3()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_BBL_CR_CTL3,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_BBL_CR_CTL3 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_SYSENTER_CS
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_sysenter_cs()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_SYSENTER_CS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_SYSENTER_CS is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_SYSENTER_ESP.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_sysenter_esp()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_SYSENTER_ESP,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_SYSENTER_ESP is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_SYSENTER_EIP.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_sysenter_eip()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_SYSENTER_EIP,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_SYSENTER_EIP is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_MCG_CAP.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_mcg_cap()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_MCG_CAP,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_MCG_CAP is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_MCG_STATUS.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_mcg_status()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_MCG_STATUS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_MCG_STATUS is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_MCG_CTL
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_mcg_ctl()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_MCG_CTL,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_MCG_CTL is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_MCG_EXT_CTL
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_mcg_ext_ctl()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_MCG_EXT_CTL,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_MCG_EXT_CTL is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_OFFCORE_RSP_0
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_offcore_rsp_0()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_OFFCORE_RSP_0,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_OFFCORE_RSP_0 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_OFFCORE_RSP_1
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_offcore_rsp_1()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_OFFCORE_RSP_1,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_OFFCORE_RSP_1 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_TURBO_RATIO_LIMIT
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_turbo_ratio_limit()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_TURBO_RATIO_LIMIT,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_TURBO_RATIO_LIMIT is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_TURBO_RATIO_LIMIT1
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_turbo_ratio_limit1()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_TURBO_RATIO_LIMIT1,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_TURBO_RATIO_LIMIT1 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_TURBO_RATIO_LIMIT2
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_turbo_ratio_limit2()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_TURBO_RATIO_LIMIT2,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_TURBO_RATIO_LIMIT2 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_PEBS_ENABLE
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_pebs_enable()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_PEBS_ENABLE,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_PEBS_ENABLE is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_DS_AREA
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_ds_area()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_DS_AREA,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_DS_AREA is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_PERF_CAPABILITIES
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_perf_capabilities()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_PERF_CAPABILITIES,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_PERF_CAPABILITIES is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_PEBS_LD_LAT_THRESHOLD.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_pebs_ld_lat_threshold()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_PEBS_LD_LAT_THRESHOLD,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_PEBS_LD_LAT_THRESHOLD is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_K8_TSEG_ADDR.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_k8_tseg_addr()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_K8_TSEG_ADDR,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_K8_TSEG_ADDR is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_K8_TSEG_MASK.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_k8_tseg_mask()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_K8_TSEG_MASK,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_K8_TSEG_MASK is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_AMD64_DC_CFG.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_amd64_dc_cfg()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_AMD64_DC_CFG,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_AMD64_DC_CFG is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_K7_EVNTSEL1.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_k7_evntsel1()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_K7_EVNTSEL1,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_K7_EVNTSEL1 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_K7_EVNTSEL2.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_k7_evntsel2()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_K7_EVNTSEL2,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_K7_EVNTSEL2 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_K7_EVNTSEL3.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_k7_evntsel3()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_K7_EVNTSEL3,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_K7_EVNTSEL3 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_K7_PERFCTR1.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_k7_perfctr1()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_K7_PERFCTR1,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_K7_PERFCTR1 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_K7_PERFCTR2.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_k7_perfctr2()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_K7_PERFCTR2,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_K7_PERFCTR2 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_K7_PERFCTR3.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_k7_perfctr3()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_K7_PERFCTR3,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_K7_PERFCTR3 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_SMM_MONITOR_CTL
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_smm_monitor_ctl()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_SMM_MONITOR_CTL,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_SMM_MONITOR_CTL is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_SMBASE.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_smbase()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_SMBASE,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_SMBASE is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read MSR_IA32_FEATURE_CONTROL.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_feature_control()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_FEATURE_CONTROL,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_FEATURE_CONTROL is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_RESET
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_reset()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_RESET,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_RESET is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_VP_RUNTIME
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_vp_runtime()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_VP_RUNTIME,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_VP_RUNTIME is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_TIME_REF_COUNT.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_time_ref_count()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_TIME_REF_COUNT,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_TIME_REF_COUNT is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_TSC_FREQUENCY
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_tsc_frequency()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_TSC_FREQUENCY,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_TSC_FREQUENCY is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_APIC_FREQUENCY.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_apic_frequency()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_APIC_FREQUENCY,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_APIC_FREQUENCY is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_CRASH_P0.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_crash_p0()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_CRASH_P0,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_CRASH_P0 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_CRASH_P1.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_crash_p1()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_CRASH_P1,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_CRASH_P1 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_CRASH_P2.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_crash_p2()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_CRASH_P2,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_CRASH_P2 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_CRASH_P3.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_crash_p3()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_CRASH_P3,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_CRASH_P3 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_CRASH_P4.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_crash_p4()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_CRASH_P4,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_CRASH_P4 is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_CRASH_CTL.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_crash_ctl()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_CRASH_CTL,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_CRASH_CTL is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_CRASH_CTL_NOTIFY.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
/* FIXME: Can't compile

int test_hv_x64_msr_crash_ctl_notify()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_CRASH_CTL_NOTIFY,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_CRASH_CTL_NOTIFY is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}*/

// This function use fork to create a child process. The child process tries to read HV_X64_MSR_CRASH_PARAMS.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_hv_x64_msr_crash_params()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(HV_X64_MSR_CRASH_PARAMS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: HV_X64_MSR_CRASH_PARAMS is");
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				return 0;
			}
			else
			{
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			return 0;	//child process exit abnormally, the register is not readable.
		}
	}
	return 1;
}

