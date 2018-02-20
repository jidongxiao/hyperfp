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

// Thie function use fork to create a child process. The child process tries to read MSR_EFER.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if bug exist, 0 if not sure.
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
		DPRINTF("DEBUG: Child: MSR_EFER is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: The return code of child process is non zero.\n");
				DPRINTF("DEBUG: Parent: MSR_EFER is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: The return code of child process is zero.\n");
				DPRINTF("DEBUG: Parent: MSR_EFER is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_EFER is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable.
		}
		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
	}
	return 1; // why would the code come to here??
}

// Thie function use fork to create a child process. The child process tries to read MSR_FS_BASE.
// If the register exists, it is readable. Otherwise, it is not readable.
// Return: 1 if bug exist, 0 if not sure.
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
		DPRINTF("DEBUG: Child: MSR_EFER is readable!\n");
		exit(0);
	}else		//parent process
	{
		wait(&status);
		if(WIFEXITED(status)) // Based on the glibc manual, this macro returns a nonzero value if the child process terminated normally with exit or __exit.
		{
			if(WEXITSTATUS(status)) // If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process
			{
				DPRINTF("DEBUG: Parent: The return code of child process is non zero.\n");
				DPRINTF("DEBUG: Parent: MSR_EFER is not readable!\n");
				return 0;
			}
			else
			{
				DPRINTF("DEBUG: Parent: The return code of child process is zero.\n");
				DPRINTF("DEBUG: Parent: MSR_EFER is readable!\n");
				return 1;	//child process exit normally with exit code 0, which means the register is readable, so the bug is not existing.
			}
		}else
		{
			DPRINTF("DEBUG: Parent: MSR_EFER is not readable!\n");
			return 0;	//child process exit abnormally, the register is not readable, so the bug is existing.
		}
		DPRINTF("DEBUG: Parent: %s %d \n",__FUNCTION__,__LINE__);
	}
	return 1;
}
