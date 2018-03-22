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

#endif /* readtest.h */
