/*test See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

//static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "0", "+5%",  NULL };
static const char *upvol[]   = {"volume", "+5%",  NULL };
static const char *downvol[] = {"volume", "-5%",  NULL };
static const char *mutevol[] = { "volume","mute",NULL };
//static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "0", "toggle",  NULL };
//static const char *hibernate[] = { "sudo", "systemctl", "suspend", NULL };
static const char *hibernate[] = {"hibernet", NULL };
static const char *capture[] = { "maimpick",   NULL };
static const char *screencopy[] = {"screencopy",   NULL };
static const char *slock[] = { "syslock", NULL };
static const char *surf[] = { "qutebrowser",  NULL };
static const char *chrome[] = { "google-chrome-stable",  NULL };
static const char *bgh[] = { "bgh",  NULL };

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=12" };
static const char dmenufont[]       = "monospace:size=20";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *passmenu[]  = { "passmenu", NULL };
static const char *restartcmd[] = { "reboot", NULL};
static const char *shutdowncmd[] = { "poweroff", NULL};
static const char *webcmd[] = { "firefox", NULL};
static const char *webcmd2[] = { "firefox", NULL};
static const char *filecmd[] = { "st", "-e", "ranger", NULL};
//static const char *filecmd[] = { "st", "-e", "lf", NULL};
static const char *filecmd2[] = { "thunar", NULL};
//static const char *filecmd[] = { "st", "-e", "lf", NULL};
static const char *calcmd[] = { "st", "-e" , "bc","-lq", NULL };
static const char *infocmd[] = { "st", "-e" , "htop", NULL };
static const char *calender[] = { "st", "-e" , "calcurse", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = webcmd2} },
	{ 0,                            XF86XK_HomePage, spawn, {.v = webcmd} },
	{ 0,                            XF86XK_Explorer, spawn, {.v = filecmd} },
	{ MODKEY,                       XK_r,      spawn,          {.v = filecmd } },
	{ MODKEY|ShiftMask,                       XK_r,      spawn,          {.v = filecmd2 } },
	{ MODKEY, XK_v, spawn, SHCMD("dropbox &; virtualbox") }, 
	{ MODKEY, XK_n, spawn, SHCMD("st -e nmtui") }, 
	{ MODKEY,                       XK_a,      spawn,          {.v = calender } },
	{ MODKEY,                       XK_w,      spawn,          {.v = surf} },
	{ MODKEY,                       XK_g,      spawn,          {.v = chrome} },
	{ MODKEY,                       XK_f,      spawn,          {.v = filecmd2} },
	{ MODKEY,                       XK_z,      spawn,          {.v = bgh} },
	{ MODKEY|ShiftMask,             XK_i,      spawn,          {.v = infocmd } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = capture } },
	{ MODKEY,             XK_s,      spawn,          {.v = screencopy} },
	{ MODKEY,                       XK_c,      spawn,          {.v = calcmd } },
	{ 0,                            XF86XK_Calculator, spawn, {.v = calcmd} },
    { 0,                XK_Print,   spawn,      SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
	{ MODKEY|ShiftMask,             XK_BackSpace,      spawn,          {.v = restartcmd} },
	{ MODKEY|ShiftMask,             XK_x,      spawn,          {.v = shutdowncmd} },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,                       XK_p,      spawn,          {.v = passmenu } },
	{ MODKEY,                       XK_x,      spawn,          {.v = slock } },
	{ MODKEY,                       XF86XK_MenuKB,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
//	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	//{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_F2,      quit,          {0} },
	{ MODKEY,                       XK_F4,      spawn, {.v = hibernate} },
	{ 0,                            XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                            XF86XK_AudioMute, spawn, {.v = mutevol } },
	{ 0, 			        XF86XK_AudioRaiseVolume, spawn, {.v = upvol } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

