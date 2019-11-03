/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 8;        /* border pixel of windows */
static const unsigned int snap      = 20;       /* snap pixel */
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static const int smartgaps = 0;                 /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "RobotoMono:size=10" };
static const char dmenufont[]       = "RobotoMono:size=10";
/* colors */
#include "/home/alex/.cache/wal/colors-wal-dwm.h"

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title             tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,             0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,             1 << 8,       0,           -1 },
	{ NULL,       NULL,       "Event Tester",   0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "tile",      tile },    /* first entry is default */
	{ "float",      NULL },    /* no layout function means floating behavior */
	{ "mono",      monocle },
};

/* key definitions */
#define ALTKEY Mod1Mask
#define WINKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ WINKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ WINKEY|ShiftMask,             KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ ALTKEY,                       KEY,      tag,            {.ui = 1 << TAG} }, \
	{ ALTKEY|ShiftMask,             KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL};
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key              function        argument */
	{ WINKEY,                       XK_r,            spawn,          {.v = dmenucmd } },    /* run dmenu */
	{ WINKEY,                       XK_t,            spawn,          {.v = termcmd } },     /* start terminal (st) */
	{ WINKEY,                       XK_b,            togglebar,      {0} },                 /* toggle top bar */
	{ WINKEY,                       XK_j,            focusstack,     {.i = +1 } },          /* next window */
	{ ALTKEY,                       XK_Tab,          focusstack,     {.i = +1} },           /* next window */
	{ WINKEY,                       XK_k,            focusstack,     {.i = -1} },           /* previous window */
	{ ALTKEY|ShiftMask,             XK_Tab,          focusstack,     {.i = -1 } },          /* previous window */
	{ WINKEY,                       XK_braceright,   incnmaster,     {.i = +1 } },          /* add window to master */
	{ WINKEY,                       XK_braceleft,    incnmaster,     {.i = -1 } },          /* remove window from master */
	{ WINKEY,                       XK_bracketleft,  setmfact,       {.f = -0.05} },        /* shrink master space */
	{ WINKEY,                       XK_bracketright, setmfact,       {.f = +0.05} },        /* enlarge master space */
	{ WINKEY,                       XK_Return,       zoom,           {0} },                 /* move window to master */
	{ WINKEY,                       XK_Tab,          view,           {0} },                 /* cycle tags */
	{ WINKEY,                       XK_q,            killclient,     {0} },                 /* close window */
	{ WINKEY,                       XK_l,            setlayout,      {.v = &layouts[0]} },  /* set layout 0 (default tiling) */
	{ WINKEY,                       XK_f,            setlayout,      {.v = &layouts[1]} },  /* set layout 1 (default float) */
	{ WINKEY,                       XK_m,            setlayout,      {.v = &layouts[2]} },  /* set layout 2 (default mono) */
	{ WINKEY,                       XK_space,        setlayout,      {0} },                 /* next/previous layout */
	{ WINKEY|ShiftMask,             XK_space,        togglefloating, {0} },                 /* toggle between float/not */
	{ WINKEY,                       XK_0,            view,           {.ui = ~0 } },         /* view all windows with any tag */
	{ WINKEY|ShiftMask,             XK_0,            tag,            {.ui = ~0 } },         /* apply all tags to focused window */
	{ WINKEY,                       XK_comma,        focusmon,       {.i = -1 } },          /* focus previous screen */
	{ WINKEY,                       XK_period,       focusmon,       {.i = +1 } },          /* foucs next screen */
	{ WINKEY|ShiftMask,             XK_comma,        tagmon,         {.i = -1 } },          /* send window to previous screen */
	{ WINKEY|ShiftMask,             XK_period,       tagmon,         {.i = +1 } },          /* send window to next screen */
	{ WINKEY,                       XK_d,            toggleview,     {.v = NULL} },                 /* hide all tags */
	TAGKEYS(                        XK_1,                            0)
	TAGKEYS(                        XK_2,                            1)
	TAGKEYS(                        XK_3,                            2)
	TAGKEYS(                        XK_4,                            3)
	TAGKEYS(                        XK_5,                            4)
	TAGKEYS(                        XK_6,                            5)
	TAGKEYS(                        XK_7,                            6)
	TAGKEYS(                        XK_8,                            7)
	TAGKEYS(                        XK_9,                            8)
	{ ALTKEY|ShiftMask,             XK_q,            quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         WINKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         WINKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         WINKEY|ControlMask,  Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            WINKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            WINKEY,              Button3,        toggletag,      {0} },
};
