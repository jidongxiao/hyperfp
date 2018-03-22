/*
 * This file implements all vmx read test cases.
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_BASIC.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_basic()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_BASIC,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_BASIC is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_PINBASED_CTLS
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_pinbased_ctls()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_PINBASED_CTLS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_PINBASED_CTLS is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_PROCBASED_CTLS
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_procbased_ctls()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_PROCBASED_CTLS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_PROCBASED_CTLS is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_EXIT_CTLS
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_exit_ctls()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_EXIT_CTLS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_EXIT_CTLS is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_ENTRY_CTLS
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_entry_ctls()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_ENTRY_CTLS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_ENTRY_CTLS is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_MISC
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_misc()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_MISC,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_MISC is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_CR0_FIXED0
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_cr0_fixed0()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_CR0_FIXED0,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_CR0_FIXED0 is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_CR0_FIXED1
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_cr0_fixed1()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_CR0_FIXED1,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_CR0_FIXED1 is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_CR4_FIXED0
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_cr4_fixed0()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_CR4_FIXED0,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_CR4_FIXED0 is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_CR4_FIXED1
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_cr4_fixed1()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_CR4_FIXED1,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_CR4_FIXED1 is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_VMCS_ENUM
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_vmcs_enum()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_VMCS_ENUM,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_VMCS_ENUM is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_PROCBASED_CTLS2
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_procbased_ctls2()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_PROCBASED_CTLS2,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_PROCBASED_CTLS2 is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_EPT_VPID_CAP
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_ept_vpid_cap()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_EPT_VPID_CAP,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_EPT_VPID_CAP is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_TRUE_PINBASED_CTLS
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_true_pinbased_ctls()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_TRUE_PINBASED_CTLS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_TRUE_PINBASED_CTLS is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_TRUE_PROCBASED_CTLS
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_true_procbased_ctls()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_TRUE_PROCBASED_CTLS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_TRUE_PROCBASED_CTLS is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_TRUE_EXIT_CTLS
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_true_exit_ctls()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_TRUE_EXIT_CTLS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_TRUE_EXIT_CTLS is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_TRUE_ENTRY_CTLS
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_true_entry_ctls()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_TRUE_ENTRY_CTLS,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_TRUE_ENTRY_CTLS is");
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

// This function use fork to create a child process. The child process tries to read MSR_IA32_VMX_VMFUNC.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if readable, 0 if not.
int test_msr_ia32_vmx_vmfunc()
{
	pid_t pid;
	int status;

	if( (pid=fork()) < 0 )
	{
		perror("fail to fork\n");
	}

	if(pid==0)	//child process
	{
		rdmsr_on_cpu(MSR_IA32_VMX_VMFUNC,0);  // If the register isn't readable, than rdmsr_on_cpu would exit this process with a non-zero exit status value.
		exit(0);
	}else		//parent process
	{
		wait(&status);
		DPRINTF("DEBUG: MSR_IA32_VMX_VMFUNC is");
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

