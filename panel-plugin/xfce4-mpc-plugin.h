/* xfce4-mpc-plugin.h
 *
 * Copyright (c) 2006-2008 Landry Breuil (landry at fr.homeunix.org / gaston at gcu.info)
 * This code is licenced under a BSD-style licence.
 * (OpenBSD variant modeled after the ISC licence)
 * All rights reserved.
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <gtk/gtk.h>
#include <libxfce4panel/xfce-panel-plugin.h>
#include <libxfce4panel/xfce-hvbox.h>
#include <libxfce4panel/xfce-panel-convenience.h>

#if HAVE_LIBMPD
#include <libmpd/libmpd.h>
#if DEBUG
#include <libmpd/debug_printf.h>
#endif
#else
#include "simple-libmpd.h"
#endif /* !HAVE_LIBMPD */

typedef struct {
   XfcePanelPlugin *plugin;
   GtkTooltips *tips;
   GtkWidget *frame,*ebox,*box,*prev,*stop,*toggle,*next,*random,*repeat,*appl,*about;
   GtkWidget *playlist;
   gboolean show_frame;
   /* mpd handle */
   MpdObj *mo;
   gchar* client_appl;
   gchar* mpd_host;
   gint mpd_port;
   gchar * mpd_password;
   gboolean mpd_repeat;
   gboolean mpd_random;
} t_mpc;

typedef struct {
   t_mpc *mpc;
   GtkWidget *textbox_host;
   GtkWidget *textbox_port;
   GtkWidget *textbox_password;
   GtkWidget *textbox_client_appl;
   GtkWidget *checkbox_frame;
} t_mpc_dialog;

