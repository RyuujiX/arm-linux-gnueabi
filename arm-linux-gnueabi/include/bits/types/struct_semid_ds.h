/* Generic implementation of the semaphore struct semid_ds.
   Copyright (C) 1995-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _SYS_SEM_H
# error "Never include <bits/types/struct_semid_ds.h> directly; use <sys/sem.h> instead."
#endif

/* Data structure describing a set of semaphores.  */
#if __TIMESIZE == 32
struct semid_ds
{
  struct ipc_perm sem_perm;        /* operation permission struct */
  __time_t sem_otime;              /* last semop() time */
  __syscall_ulong_t __glibc_reserved1;
  __time_t sem_ctime;             /* last time changed by semctl() */
  __syscall_ulong_t __glibc_reserved2;
  __syscall_ulong_t sem_nsems;    /* number of semaphores in set */
  __syscall_ulong_t __glibc_reserved3;
  __syscall_ulong_t __glibc_reserved4;
};
#else
struct semid_ds
{
  struct ipc_perm sem_perm;		/* operation permission struct */
  __time_t sem_otime;			/* last semop() time */
  __time_t sem_ctime;			/* last time changed by semctl() */
  __syscall_ulong_t sem_nsems;		/* number of semaphores in set */
  __syscall_ulong_t __glibc_reserved3;
  __syscall_ulong_t __glibc_reserved4;
};
#endif
