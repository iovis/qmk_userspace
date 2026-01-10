#pragma once

enum layers {
    // Base layers (keep at top or MO() won't work)
    LAYER_BASE = 0,
    LAYER_LINUX,
    LAYER_GAME,

    LAYER_MOUSE,
    LAYER_NAV,
    LAYER_NUM, // keep under LAYER_SYM
    LAYER_SYM,

    LAYER_CALL,
    LAYER_MPV,
    LAYER_NUMFN,
    LAYER_NUMGM, // keep over LAYER_SYM
    LAYER_NUMGI,
};
