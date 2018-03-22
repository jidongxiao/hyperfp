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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_EFER,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_EFER is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_EFER is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_EFER is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_STAR,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_STAR is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_STAR is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_STAR is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_LSTAR,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_LSTAR is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_LSTAR is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_LSTAR is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_LSTAR is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_CSTAR,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_CSTAR is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_CSTAR is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_CSTAR is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_CSTAR is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_SYSCALL_MASK,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_SYSCALL_MASK is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_SYSCALL_MASK is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_SYSCALL_MASK is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_SYSCALL_MASK is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_FS_BASE,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_FS_BASE is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_FS_BASE is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_FS_BASE is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_FS_BASE is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_GS_BASE,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_GS_BASE is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_GS_BASE is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_GS_BASE is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_GS_BASE is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_KERNEL_GS_BASE,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_KERNEL_GS_BASE is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_KERNEL_GS_BASE is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_KERNEL_GS_BASE is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_KERNEL_GS_BASE is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_TSC_AUX,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_TSC_AUX is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_TSC_AUX is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_TSC_AUX is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_TSC_AUX is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_PPIN_CTL,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_PPIN_CTL is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_PPIN_CTL is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_PPIN_CTL is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_PPIN_CTL is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_PPIN,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_PPIN is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_PPIN is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_PPIN is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_PPIN is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_IA32_PERFCTR0,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_IA32_PERFCTR0 is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_IA32_PERFCTR0 is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_IA32_PERFCTR0 is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_IA32_PERFCTR0 is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_IA32_PERFCTR1,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_IA32_PERFCTR1 is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_IA32_PERFCTR1 is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_IA32_PERFCTR1 is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_IA32_PERFCTR1 is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_FSB_FREQ,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_FSB_FREQ is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_FSB_FREQ is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_FSB_FREQ is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_FSB_FREQ is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_PLATFORM_INFO,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_PLATFORM_INFO is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_PLATFORM_INFO is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_PLATFORM_INFO is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_PLATFORM_INFO is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_PLATFORM_INFO_CPUID_FAULT_BIT,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_PLATFORM_INFO_CPUID_FAULT_BIT is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_PLATFORM_INFO_CPUID_FAULT_BIT is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_PLATFORM_INFO_CPUID_FAULT_BIT is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_PLATFORM_INFO_CPUID_FAULT_BIT is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
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
		DPRINTF("DEBUG: Child: %s %d \n",__FUNCTION__,__LINE__);
		rdmsr_on_cpu(MSR_PLATFORM_INFO_CPUID_FAULT,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		DPRINTF("DEBUG: Child: MSR_PLATFORM_INFO_CPUID_FAULT is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: MSR_PLATFORM_INFO_CPUID_FAULT is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: MSR_PLATFORM_INFO_CPUID_FAULT is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_PLATFORM_INFO_CPUID_FAULT is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
//		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
	}
	return 1;
}
