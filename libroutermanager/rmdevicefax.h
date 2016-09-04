/**
 * The libroutermanager project
 * Copyright (c) 2012-2016 Jan-Michael Brummer
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef LIBROUTERMANAGER_RMDEVICEFAX_H
#define LIBROUTERMANAGER_RMDEVICEFAX_H

#include <libroutermanager/rmconnection.h>

G_BEGIN_DECLS

typedef struct device_fax {
	gchar *name;
	RmConnection *(*send)(gchar *tiff, const gchar *target, gboolean anonymous);
	gboolean (*get_status)(struct fax_status *status);
	gint (*pickup)(RmConnection *connection);
	void (*hangup)(RmConnection *connection);

	gboolean (*number_is_handled)(gchar *number);
} RmDeviceFax;

void rm_device_fax_register(RmDeviceFax *fax);
GSList *rm_device_fax_get_plugins(void);

G_END_DECLS

#endif
