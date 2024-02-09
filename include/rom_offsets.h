#ifndef ROM_OFFSETS_H
#define ROM_OFFSETS_H

#include "other_types.h"


typedef struct RomOffsetPair {
    /* 0x0 */ RomOffset start;
    /* 0x4 */ RomOffset end;
} RomOffsetPair; // size = 0x8

// Used to index storyRomData
typedef enum StoryRomDataIndex {
    /* 0 */ STORYROMDATA_COFFEE_01,
    /* 1 */ STORYROMDATA_MENU_BG,
    /* 2 */ STORYROMDATA_MENU_BG2,
    /* 3 */ STORYROMDATA_WAKU,
    /* 4 */ STORYROMDATA_WAKU2,
    /* 5 */ STORYROMDATA_TITLE_ALL,
    /* 6 */ STORYROMDATA_TITLE_BMP,
    /* 7 */ STORYROMDATA_MAX
} StoryRomDataIndex;

typedef enum BgRomDataIndex {
    /*  0 */ BGROMDATA_INDEX0,
    /*  1 */ BGROMDATA_INDEX1,
    /*  2 */ BGROMDATA_INDEX2,
    /*  3 */ BGROMDATA_INDEX3,
    /*  4 */ BGROMDATA_INDEX4,
    /*  5 */ BGROMDATA_INDEX5,
    /*  6 */ BGROMDATA_INDEX6,
    /*  7 */ BGROMDATA_INDEX7,
    /*  8 */ BGROMDATA_INDEX8,
    /*  9 */ BGROMDATA_INDEX9,
    /* 10 */ BGROMDATA_INDEX10,
    /* 11 */ BGROMDATA_INDEX11,
    /* 12 */ BGROMDATA_INDEX12,
    /* 13 */ BGROMDATA_INDEX13,
    /* 14 */ BGROMDATA_INDEX14,
    /* 15 */ BGROMDATA_INDEX15,
    /* 16 */ BGROMDATA_INDEX16,
    /* 17 */ BGROMDATA_INDEX17,
    /* 18 */ BGROMDATA_INDEX18,
    /* 19 */ BGROMDATA_INDEX19,
    /* 20 */ BGROMDATA_INDEX20,
    /* 21 */ BGROMDATA_INDEX21,
    /* 22 */ BGROMDATA_INDEX22,
    /* 23 */ BGROMDATA_INDEX23,
    /* 24 */ BGROMDATA_MAX
} BgRomDataIndex;

typedef enum RomDataTblIndex {
    /*  0 */ ROMDATATBL_N64_WAVE_TABLES,
    /*  1 */ ROMDATATBL_N64_PTR_TABLES,
    /*  2 */ ROMDATATBL_INDEX2,
    /*  3 */ ROMDATATBL_INDEX3,
    /*  4 */ ROMDATATBL_INDEX4,
    /*  5 */ ROMDATATBL_INDEX5,
    /*  6 */ ROMDATATBL_INDEX6,
    /*  7 */ ROMDATATBL_INDEX7,
    /*  8 */ ROMDATATBL_INDEX8,
    /*  9 */ ROMDATATBL_INDEX9,
    /* 10 */ ROMDATATBL_INDEX10,
    /* 11 */ ROMDATATBL_INDEX11,
    /* 12 */ ROMDATATBL_INDEX12,
    /* 13 */ ROMDATATBL_INDEX13,
    /* 14 */ ROMDATATBL_INDEX14,
    /* 15 */ ROMDATATBL_INDEX15,
    /* 16 */ ROMDATATBL_INDEX16,
    /* 17 */ ROMDATATBL_INDEX17,
    /* 18 */ ROMDATATBL_INDEX18,
    /* 19 */ ROMDATATBL_INDEX19,
    /* 20 */ ROMDATATBL_INDEX20,
    /* 21 */ ROMDATATBL_INDEX21,
    /* 22 */ ROMDATATBL_INDEX22,
    /* 23 */ ROMDATATBL_INDEX23,
    /* 24 */ ROMDATATBL_INDEX24,
    /* 25 */ ROMDATATBL_INDEX25,
    /* 26 */ ROMDATATBL_INDEX26,
    /* 27 */ ROMDATATBL_ANIME_A,
    /* 28 */ ROMDATATBL_ANIME_B,
    /* 29 */ ROMDATATBL_ANIME_C,
    /* 30 */ ROMDATATBL_ANIME_D,
    /* 31 */ ROMDATATBL_ANIME_E,
    /* 32 */ ROMDATATBL_ANIME_F,
    /* 33 */ ROMDATATBL_ANIME_G,
    /* 34 */ ROMDATATBL_ANIME_H,
    /* 35 */ ROMDATATBL_ANIME_I,
    /* 36 */ ROMDATATBL_ANIME_J,
    /* 37 */ ROMDATATBL_ANIME_K,
    /* 38 */ ROMDATATBL_ANIME_L,
    /* 39 */ ROMDATATBL_ANIME_M,
    /* 40 */ ROMDATATBL_ANIME_N,
    /* 41 */ ROMDATATBL_ANIME_O,
    /* 42 */ ROMDATATBL_ANIME_MARIO,
    /* 43 */ ROMDATATBL_ANIME_VIRUS_B,
    /* 44 */ ROMDATATBL_ANIME_VIRUS_R,
    /* 45 */ ROMDATATBL_ANIME_VIRUS_Y,
    /* 46 */ ROMDATATBL_ANIME_SMOG,
    /* 47 */ ROMDATATBL_GAME_AL,
    /* 48 */ ROMDATATBL_GAME_P1,
    /* 49 */ ROMDATATBL_GAME_P2,
    /* 50 */ ROMDATATBL_GAME_P4,
    /* 51 */ ROMDATATBL_GAME_LS,
    /* 52 */ ROMDATATBL_GAME_ITEM,
    /* 53 */ ROMDATATBL_GAME_ETC,
    /* 54 */ ROMDATATBL_MENU_CHAR,
    /* 55 */ ROMDATATBL_MENU_COMMON,
    /* 56 */ ROMDATATBL_MENU_LEVEL,
    /* 57 */ ROMDATATBL_MENU_MAIN,
    /* 58 */ ROMDATATBL_MENU_NAME,
    /* 59 */ ROMDATATBL_MENU_P2,
    /* 60 */ ROMDATATBL_MENU_P4,
    /* 61 */ ROMDATATBL_MENU_RANK,
    /* 62 */ ROMDATATBL_MENU_SETUP,
    /* 63 */ ROMDATATBL_MENU_STORY,
    /* 64 */ ROMDATATBL_MENU_CONT,
    /* 65 */ ROMDATATBL_MENU_KASA,
    /* 66 */ ROMDATATBL_TUTORIAL_KASA,
    /* 67 */ ROMDATATBL_MAX
} RomDataTblIndex;

extern RomOffsetPair storyRomData[];
extern RomOffsetPair bgRomData[];
extern RomOffsetPair _romDataTbl[];

#endif
