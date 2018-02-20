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
        [1]             = test_msr_fs_base,
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
			DPRINTF("MSR xxx is readable\n");
		else
			DPRINTF("MSR xxx is not readable\n");
			
	}

	DPRINTF("===Starting MSR Write Test!===\n");
	for(i=0;i<kvm_msr_write_max;i++)
	{
		//Write Test MSR i;
		DPRINTF("MSR xxx is writable\n");
	}

        return 0;
}

