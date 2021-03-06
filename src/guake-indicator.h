/*
Copyright (C) 2013-2018 Alessio Garzi <gun101@email.it>
Copyright (C) 2013-2018 Francesco Minà <mina.francesco@gmail.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public
License along with this program; if not, write to the
Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.
* */

#include <glib.h>
#include <gtk/gtk.h>

#define GUAKE_INDICATOR_DEFAULT_DIR ".guake-indicator"
#define GUAKE_INDICATOR_PLUGIN_DIR "plugins"
#define GUAKE_INDICATOR_ICON_DIR "icons/hicolor/256x256/apps/"
#define GUAKE_INDICATOR_DCONF_SCHEMA_ROOT "org.guake-indicator.data"
#define GUAKE_INDICATOR_VERSION "1.3.3"

typedef struct Host {
	gchar* id;
	gboolean label;
	gchar* hostname;
	gchar* login;
	gchar* menu_name;
	gchar* tab_name;
	gchar* command_after_login;
	gchar* remote_command;
	gchar* x_forwarded;
	gchar* dont_show_guake;
	gchar* open_in_tab;
	gboolean open_in_tab_named;
	gchar* lfcr;
	gchar* guakeindicatorscript;
	
	gboolean open_all;
	struct Host* next;
	struct Host* previous;
	struct Host* group_head;
	struct HostGroup* parent;
} Host;

typedef struct HostGroup {
	gchar* id;
	gchar* title;
	Host* hostarray;
	gboolean label;
}HostGroup;

typedef struct GtkInfo {
	GtkActionGroup* action_group;
	GtkUIManager * uim;
	GArray* grouphostlist;
} GtkInfo;

void reload(GtkAction*,gpointer);
static void activate_action (GtkAction* );
static void guake_open(GtkAction*,gpointer);
static void guake_open_with_show(GtkAction*,gpointer);
static void group_guake_open(GtkAction*,gpointer);
static void about(GtkAction*);
static void close_guake ( GtkWidget *, gpointer);
static void update_json(gpointer);

gchar* add_host_to_menu(Host*,GtkActionGroup *);
gchar* add_lable_to_menu(HostGroup*,GtkActionGroup *);
void create_default_actions(GtkActionGroup*,GtkInfo*);
gchar* create_actionlists(GArray*,GtkUIManager*,GtkActionGroup*);
void grouphostlist_free(GArray*);
void host_free(Host*);
void hostgroup_free(HostGroup*);
int findguakepid();

void error_modal_box (const char*);
