/*
 * vim:expandtab:shiftwidth=8:tabstop=8:
 *
 * Copyright CEA/DAM/DIF  (2008)
 * contributeur : Philippe DENIEL   philippe.deniel@cea.fr
 *                Thomas LEIBOVICI  thomas.leibovici@cea.fr
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * ---------------------------------------
 */

/**
 * \file    $RCSfile: SemN.c,v $
 * \author  $Author: deniel $
 * \date    $Date: 2005/11/28 17:02:56 $
 * \brief   Portable system tools.
 *
 * Implements system utilities (like semaphores)
 * so that they are POSIX and work on
 * most plateforms.
 *
 * CVS history :
 *
 * $Log: SemN.c,v $
 *
 * Revision 1.2  2005/03/15 14:23:47  leibovic
 * Changing init param.
 *
 * Revision 1.1  2004/08/16 09:41:21  deniel
 * Ajout des semaphores a N entrees de Thomas (fait au depart pour hpss_find)
 *
 * Revision 1.3  2004/06/28 09:26:53  leibovic
 * gestion des signaux
 *
 * Revision 1.2  2004/06/24 09:41:18  leibovic
 * ajout des fonctionnalite user et group.
 *
 * Revision 1.1  2004/06/11 12:18:05  leibovic
 * rename tools en systools
 *
 * Revision 1.2  2004/06/07 14:17:10  leibovic
 * Developpement du module de gestion des options de la ligne de commande.
 *
 * Revision 1.1  2004/06/03 14:54:22  leibovic
 * Developpement de semaphores "portables"
 *
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <errno.h>
#include "SemN.h"
#include <stdio.h>
#include <semaphore.h>

#define MODULE "SemN"

int semaphore_init(semaphore_t * sem, unsigned int value)
{
  if(!sem)
    return EINVAL;

   return sem_init(&sem->semaphore,
                   0 /* Not shared accross processes */, 
                   value) ;
}

int semaphore_destroy(semaphore_t * sem)
{

  if(!sem)
    return EINVAL;

  return sem_destroy( &sem->semaphore ) ;
}

void semaphore_P(semaphore_t * sem)
{
    sem_wait( &sem->semaphore ); 
}

void semaphore_V(semaphore_t * sem)
{
    sem_post( &sem->semaphore ) ;
}
