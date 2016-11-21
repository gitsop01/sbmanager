/**
 * sb.device.h
 * Device communication functions (header file)
 *
 * Copyright (C) 2009-2010 Nikias Bassen <nikias@gmx.li>
 * Copyright (C) 2009-2010 Martin Szulecki <opensuse@sukimashita.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more profile.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335
 * USA
 */
#ifndef DEVICE_H
#define DEVICE_H
#include <glib.h>
#include <libimobiledevice/sbservices.h>

struct device_info_int {
    char *uuid;
    char *device_name;
    char *device_type;
    guint battery_capacity;
    guint battery_poll_interval;
    /* layout on iOS 3.2+ */
    guint home_screen_icon_columns;
    guint home_screen_icon_dock_max_count;
    guint home_screen_icon_height;
    guint home_screen_icon_rows;
    guint home_screen_icon_width;
    /* folders on iOS 4+ */
    guint icon_folder_columns;
    guint icon_folder_max_pages;
    guint icon_folder_rows;
    gboolean icon_state_saves;
};
typedef struct device_info_int *device_info_t;

void device_init();
sbservices_client_t device_sbs_new(const char *uuid, uint32_t *osversion, GError **error);
void device_sbs_free(sbservices_client_t sbc);
gboolean device_sbs_get_iconstate(sbservices_client_t sbc, plist_t *iconstate, const char *format_version, GError **error);
gboolean device_sbs_save_icon(sbservices_client_t sbc, char *display_identifier, char *filename, GError **error);
gboolean device_sbs_set_iconstate(sbservices_client_t sbc, plist_t iconstate, GError **error);
char *device_sbs_save_wallpaper(sbservices_client_t sbc, const char *uuid, GError **error);

device_info_t device_info_new();
void device_info_free(device_info_t device_info);
gboolean device_poll_battery_capacity(const char *uuid, device_info_t *device_info, GError **error);
gboolean device_get_info(const char *uuid, device_info_t *device_info, GError **error);
extern gboolean VERBOSE;

#endif
