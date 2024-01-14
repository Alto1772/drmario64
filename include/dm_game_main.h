#ifndef DM_GAME_MAIN_H
#define DM_GAME_MAIN_H

#include "libultra.h"
#include "ai.h"
#include "char_anime.h"
#include "gamemap.h"
#include "msgwnd.h"
#include "recwritingmsg.h"
#include "main.h"
#include "unk.h"

struct struct_virus_map_data;
struct struct_virus_map_disp_order;
struct NNSched;

typedef enum enum_evs_gamemode {
    /* 0 */ ENUM_EVS_GAMEMODE_0,
    /* 1 */ ENUM_EVS_GAMEMODE_1,
    /* 2 */ ENUM_EVS_GAMEMODE_2,
    /* 3 */ ENUM_EVS_GAMEMODE_3
} enum_evs_gamemode;

typedef struct struct_gameGeom {
    /* 0x0000 */ Mtx mtxBuf[3][0x20];
    /* 0x1800 */ Vtx vtxBuf[3][0x80];
} struct_gameGeom; // size = 0x3000

typedef struct dm_calc_erase_score_pos_arg2 {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
} dm_calc_erase_score_pos_arg2; // size >= 0x8

typedef struct struct_watchGame_unk_9D0 {
    /* 0x00 */ UNK_TYPE unk_00;
    /* 0x04 */ UNK_TYPE unk_04;
    /* 0x08 */ UNK_TYPE unk_08;
    /* 0x0C */ UNK_TYPE unk_0C;
    /* 0x10 */ UNK_TYPE unk_10;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ UNK_TYPE unk_18;
    /* 0x1C */ UNK_TYPE unk_1C;
    /* 0x20 */ UNK_TYPE unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
} struct_watchGame_unk_9D0; // size = 0x2C

typedef struct struct_watchGame_unk_0B8_unk_00 {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ UNK_TYPE4 unk_04;
    /* 0x08 */ UNK_TYPE4 unk_08;
    /* 0x0C */ UNK_TYPE4 unk_0C;
    /* 0x10 */ f32 unk_10;
} struct_watchGame_unk_0B8_unk_00; // size = 0x14

typedef struct struct_watchGame_unk_0B8 {
    /* 0x00 */ struct_watchGame_unk_0B8_unk_00 unk_00[8];
    /* 0xA0 */ UNK_TYPE4 unk_A0;
} struct_watchGame_unk_0B8; // size = 0xA4

typedef struct struct_watchGame_unk_070 {
    /* 0x00 */ UNK_TYPE *unk_00;
    /* 0x04 */ UNK_TYPE *unk_04;
    /* 0x08 */ s32 unk_08[0x10];
} struct_watchGame_unk_070; // size = 0x48

#define ANIMES_COUNT 3

typedef struct struct_watchGame {
    /* 0x000 */ UNK_TYPE4 unk_000;
    /* 0x004 */ s32 unk_004;
    /* 0x008 */ s32 unk_008;
    /* 0x00C */ s32 unk_00C[0xC];
    /* 0x03C */ s32 unk_03C[0xC];
    /* 0x06C */ s32 unk_06C;
    /* 0x070 */ struct_watchGame_unk_070 unk_070;
    /* 0x0B8 */ struct_watchGame_unk_0B8 unk_0B8[4];
    /* 0x348 */ UNK_TYPE4 unk_348[UNK_SIZE];
    /* 0x34C */ UNK_TYPE1 unk_34C[0xC];
    /* 0x358 */ UNK_TYPE4 unk_358[UNK_SIZE];
    /* 0x35C */ UNK_TYPE1 unk_35C[0xC];
    /* 0x368 */ UNK_TYPE4 unk_368[UNK_SIZE];
    /* 0x36C */ UNK_TYPE1 unk_36C[0xC];
    /* 0x378 */ UNK_TYPE4 unk_378;
    /* 0x37C */ s32 unk_37C[4];
    /* 0x38C */ UNK_TYPE unk_38C;
    /* 0x390 */ UNK_TYPE unk_390;
    /* 0x394 */ s32 unk_394;
    /* 0x398 */ s32 unk_398;
    /* 0x39C */ s32 unk_39C[4];
    /* 0x3AC */ s32 unk_3AC;
    /* 0x3B0 */ s32 unk_3B0;
    /* 0x3B4 */ s32 unk_3B4;
    /* 0x3B8 */ s32 unk_3B8;
    /* 0x3BC */ s32 unk_3BC; // enum_evs_gamemode?
    /* 0x3C0 */ s32 unk_3C0;
    /* 0x3C4 */ s32 unk_3C4;
    /* 0x3C8 */ f32 unk_3C8;
    /* 0x3CC */ f32 unk_3CC;
    /* 0x3D0 */ f32 unk_3D0[ANIMES_COUNT][2];
    /* 0x3E8 */ f32 unk_3E8[3];
    /* 0x3F4 */ f32 unk_3F4[ANIMES_COUNT];
    /* 0x400 */ UNK_TYPE4 unk_400[3]; // bool?
    /* 0x40C */ s32 unk_40C;
    /* 0x410 */ UNK_TYPE unk_410;
    /* 0x414 */ s32 unk_414;
    /* 0x418 */ u8 unk_418[3];
    /* 0x41B */ UNK_TYPE1 pad_41B[1]; // pad?
    /* 0x41C */ s32 unk_41C;
    /* 0x420 */ s32 unk_420;
    /* 0x424 */ s32 unk_424;
    /* 0x428 */ UNK_TYPE4 unk_428;
    /* 0x42C */ UNK_TYPE1 unk_42C[0x4];
    /* 0x430 */ struct TiTexData *unk_430;
    /* 0x434 */ struct TiTexData *unk_434;
    /* 0x438 */ struct TiTexData *unk_438;
    /* 0x43C */ struct TiTexData *unk_43C;
    /* 0x440 */ struct TiTexData *unk_440;
    /* 0x444 */ struct TiTexData *unk_444;
    /* 0x448 */ struct TiTexData *unk_448;
    /* 0x44C */ AnimeState animeStates[ANIMES_COUNT];
    /* 0x50C */ AnimeSmog animeSmogs[ANIMES_COUNT];
    /* 0x878 */ UNK_TYPE unk_878;
    /* 0x87C */ TexturePtr unk_87C; // SnapBg?
    /* 0x880 */ s32 unk_880;
    /* 0x884 */ UNK_PTR unk_884;
    /* 0x888 */ UNK_TYPE4 unk_888[UNK_SIZE];
    /* 0x88C */ UNK_TYPE1 unk_88C[0xC];
    /* 0x898 */ s32 unk_898;
    /* 0x89C */ s32 unk_89C[4];
    /* 0x8AC */ s32 unk_8AC[2];
    /* 0x8B4 */ s32 unk_8B4[2];
    /* 0x8BC */ s32 unk_8BC;
    /* 0x8C0 */ s32 unk_8C0;
    /* 0x8C4 */ s32 unk_8C4;
    /* 0x8C8 */ s32 unk_8C8;
    /* 0x8CC */ s32 unk_8CC[4];
    /* 0x8DC */ s32 unk_8DC[4][4];
    /* 0x91C */ MessageWnd messageWnd;
    /* 0x99C */ s32 unk_99C;
    /* 0x9A0 */ s32 unk_9A0[3];
    /* 0x9AC */ s32 unk_9AC; // TODO: func_8006A938 implies this member is part of unk_9A0, but it doesn't seem to make much sense to do so
    /* 0x9B0 */ s32 unk_9B0;
    /* 0x9B4 */ s32 unk_9B4;
    /* 0x9B8 */ s32 unk_9B8;
    /* 0x9BC */ s32 unk_9BC;
    /* 0x9C0 */ UNK_TYPE4 unk_9C0;
    /* 0x9C4 */ UNK_TYPE4 unk_9C4;
    /* 0x9C8 */ s32 unk_9C8;
    /* 0x9CC */ s32 unk_9CC;
    /* 0x9D0 */ struct_watchGame_unk_9D0 unk_9D0[2];
    /* 0xA28 */ MessageWnd unk_A28;
    /* 0xAA8 */ s32 unk_AA8;
    /* 0xAAC */ unsigned char unk_AAC[42]; // passwordPrompt?
    /* 0xAD8 */ RecordWritingMessage recMessage;
} struct_watchGame; // size = 0xB60

// not sure about this struct
typedef struct struct_game_state_data_unk_0D4_unk_00 {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ s32 unk_8;
} struct_game_state_data_unk_0D4_unk_00; // size = 0xC

typedef struct struct_game_state_data_unk_0D4 {
    /* 0x00 */ struct_game_state_data_unk_0D4_unk_00 unk_00[UNK_SIZE];
    /* 0x0C */ UNK_TYPE1 unk_0C[0x60];
} struct_game_state_data_unk_0D4; // size = 0x6C

typedef struct struct_game_state_data_unk_140 {
    /* 0x00 */ UNK_TYPE4 unk_00[UNK_SIZE];
    /* 0x04 */ UNK_TYPE1 unk_04[0x20];
} struct_game_state_data_unk_140; // size = 0x24

typedef struct struct_game_state_data_unk_178 {
    /* 0x0 */ s8 unk_0[2];
    /* 0x0 */ s8 unk_2[2];
    /* 0x0 */ s8 unk_4[2];
    /* 0x0 */ s8 unk_6[2];
    /* 0x0 */ s8 unk_8;
    /* 0x0 */ s8 unk_9;
    /* 0x0 */ s8 unk_A;
} struct_game_state_data_unk_178; // size = 0xB

typedef struct struct_game_state_data_unk_050 {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk_2;
} struct_game_state_data_unk_050; // size = 0x4

typedef struct struct_game_state_data {
    /* 0x000 */ u32 unk_000;
    /* 0x004 */ u16 unk_004;
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ s16 unk_008;
    /* 0x008 */ s8 unk_00A;
    /* 0x008 */ UNK_TYPE1 unk_00B[0x1];
    /* 0x00C */ s32 unk_00C;
    /* 0x010 */ s32 unk_010;
    /* 0x014 */ u32 unk_014; // TODO: enum?
    /* 0x018 */ s32 unk_018;
    /* 0x01C */ UNK_TYPE4 unk_01C;
    /* 0x020 */ u32 unk_020;
    /* 0x024 */ u8 unk_024;
    /* 0x025 */ u8 unk_025;
    /* 0x026 */ u8 unk_026;
    /* 0x027 */ u8 unk_027;
    /* 0x028 */ s8 unk_028;
    /* 0x029 */ u8 unk_029;
    /* 0x02A */ u8 unk_02A;
    /* 0x02B */ u8 unk_02B;
    /* 0x02C */ u8 unk_02C;
    /* 0x02D */ u8 unk_02D;
    /* 0x02E */ u8 unk_02E;
    /* 0x02F */ u8 unk_02F;
    /* 0x030 */ u8 unk_030;
    /* 0x031 */ u8 unk_031;
    /* 0x032 */ u8 unk_032;
    /* 0x033 */ u8 unk_033;
    /* 0x034 */ s8 unk_034;
    /* 0x035 */ u8 unk_035;
    /* 0x036 */ u8 unk_036;
    /* 0x037 */ u8 unk_037;
    /* 0x038 */ u8 unk_038;
    /* 0x039 */ u8 unk_039;
    /* 0x03A */ u8 unk_03A;
    /* 0x03B */ u8 unk_03B;
    /* 0x03C */ u8 unk_03C[4];
    /* 0x040 */ u8 unk_040;
    /* 0x041 */ UNK_TYPE1 unk_041[0x3];
    /* 0x040 */ UNK_TYPE unk_044;
    /* 0x048 */ u8 unk_048;
    /* 0x048 */ u8 unk_049;
    /* 0x048 */ u8 unk_04A;
    /* 0x04B */ u8 unk_04B;
    /* 0x04C */ u8 unk_04C;
    /* 0x04D */ s8 unk_04D;
    /* 0x04E */ u8 unk_04E;
    /* 0x04F */ u8 unk_04F;
    /* 0x050 */ struct_game_state_data_unk_050 unk_050[0x10];
    /* 0x090 */ CharAnimeMode unk_090;
    /* 0x094 */ AnimeState unk_094;
    /* 0x0D4 */ struct_game_state_data_unk_0D4 unk_0D4;
    /* 0x140 */ struct_game_state_data_unk_140 unk_140;
    /* 0x164 */ s32 unk_164;
    /* 0x168 */ s32 unk_168;
    /* 0x16C */ s32 unk_16C;
    /* 0x170 */ UNK_TYPE4 unk_170;
    /* 0x174 */ UNK_TYPE4 unk_174;
    /* 0x178 */ struct_game_state_data_unk_178 unk_178;
    /* 0x183 */ UNK_TYPE1 unk_183[1];
    /* 0x184 */ struct_game_state_data_unk_178 unk_184;
    /* 0x18F */ UNK_TYPE1 unk_18F[1];
    /* 0x190 */ struct_aiFlag unk_190;
    /* 0x1D0 */ u8 unk_1D0[AIROOT_LEN][2];
    /* 0x234 */ u8 unk_234;
    /* 0x235 */ u8 unk_235;
    /* 0x236 */ u8 unk_236;
    /* 0x237 */ u8 unk_237;
    /* 0x238 */ u8 unk_238;
    /* 0x239 */ s8 unk_239;
    /* 0x23A */ u8 unk_23A;
    /* 0x23A */ u8 unk_23B;
    /* 0x23C */ u8 unk_23C;
    /* 0x23D */ u8 unk_23D;
    /* 0x23E */ u8 unk_23E;
    /* 0x23F */ u8 unk_23F;
    /* 0x240 */ u8 unk_240;
    /* 0x241 */ u8 unk_241;
    /* 0x242 */ u8 unk_242[0x10];
    /* 0x252 */ UNK_TYPE1 unk_252[2];
    /* 0x254 */ UNK_TYPE1 unk_254[0x1C];
    /* 0x270 */ UNK_TYPE1 unk_270[2];
    /* 0x272 */ s16 unk_272[0x10];
    /* 0x292 */ u8 unk_292;
    /* 0x293 */ u8 unk_293;
    /* 0x294 */ u8 unk_294;
    /* 0x295 */ UNK_TYPE1 unk_295[0x3];
    /* 0x298 */ u8 unk_298;
    /* 0x299 */ UNK_TYPE1 unk_299[0x3];
    /* 0x29C */ u8 unk_29C[GAME_MAP_ROWS][GAME_MAP_COLUMNS][2];
    /* 0x34C */ UNK_TYPE1 unk_3AC[0x10];
    /* 0x3BC */ u8 unk_3BC;
    /* 0x3BD */ u8 unk_3BD;
    /* 0x3BE */ UNK_TYPE1 unk_3BE[0x2];
    /* 0x3C0 */ u8 unk_3C0;
    /* 0x3C1 */ u8 unk_3C1;
    /* 0x3C2 */ UNK_TYPE1 unk_3C2[0x2];
} struct_game_state_data; // size = 0x3C4

UNK_TYPE func_800601F0(struct_game_state_data *gameStateDataRef, s32 arg1);
void func_80060270(struct_game_state_data * gameStateDataRef, UNK_TYPE arg1);
UNK_TYPE dm_make_score(struct_game_state_data *arg0);
void dm_attack_se(struct_game_state_data *gameStateData, s32 arg1);
void dm_warning_h_line(struct_game_state_data *gameStateData, GameMapCell *mapCells);
UNK_TYPE set_down_flg(GameMapCell *mapCells);
void go_down(struct_game_state_data *gameStateData, GameMapCell *mapCells, s32 arg2);
void erase_anime(GameMapCell *mapCells);
// void func_800609B8();
void translate_capsel(GameMapCell *mapCells, struct_game_state_data * arg1, s32 arg2, s32 arg3);
void rotate_capsel(GameMapCell *mapCells, struct_game_state_data_unk_178 *arg1, s32 arg2);
void dm_make_magazine(void);
void func_80060F60(struct_game_state_data_unk_178 *arg0, s32 arg1, s32 arg2);
void func_80060FA0(struct_game_state_data_unk_178 *arg0, s32 arg1, s32 arg2);
void dm_set_capsel(struct_game_state_data *arg0);
void dm_capsel_speed_up(struct_game_state_data *gameStateDataRef);
bool dm_check_game_over(struct_game_state_data *gameStateDataRef, GameMapCell *mapCells);
s32 update_flash_virus_count(struct_game_state_data *arg0, GameMapCell *mapCells, s32 arg2);
u8 func_8006121C(struct_game_state_data *gameStateDataRef, GameMapCell *mapCells, UNK_TYPE arg2);
void dm_set_virus(struct_game_state_data *gameStateDataRef, GameMapCell *mapCells, struct struct_virus_map_data *virusMapData, struct struct_virus_map_disp_order *virusMapDispOrder);
void dm_virus_anime(struct_game_state_data *arg0, GameMapCell *mapCells);
void dm_capsel_erase_anime(struct_game_state_data *gameStateDataRef, GameMapCell *mapCells);
void dm_make_erase_h_line(struct_game_state_data *arg0, GameMapCell *mapCells, s32 rowStart, s32 count, s32 column);
bool dm_h_erase_chack(GameMapCell *mapCells);
void dm_h_erase_chack_set(struct_game_state_data *gameStateDataRef, GameMapCell *mapCells);
void dm_make_erase_w_line(struct_game_state_data *arg0, GameMapCell *mapCells, s32 columnStart, s32 count, s32 row);
bool dm_w_erase_chack(GameMapCell *mapCells);
void dm_w_erase_chack_set(struct_game_state_data *arg0, GameMapCell *mapCells);
void dm_h_ball_chack(GameMapCell *mapCells);
void dm_w_ball_chack(GameMapCell *mapCells);
bool dm_black_up(struct_game_state_data *gameStateDataP, GameMapCell *mapCells);
bool dm_broken_set(struct_game_state_data *gameStateData, GameMapCell *mapCells);
void dm_calc_erase_score_pos(struct_game_state_data *arg0, GameMapCell *mapCells, dm_calc_erase_score_pos_arg2 *arg2);
s32 dm_calc_capsel_pos(struct_game_state_data *gameStateDataRef, s32 arg1[2], s32 arg2[2]);
void dm_draw_capsel_by_gfx(struct_game_state_data *gameStateData, s32 *arg1, s32 *arg2);
// void dm_draw_capsel_by_cpu_tentative();
UNK_PTR *dm_game_heap_top(void);
AnimeState *get_virus_anime_state(s32 arg0);
AnimeSmog *get_virus_smog_state(s32 arg0);
Mtx *dm_get_mtx_buf(void);
Vtx *dm_get_vtx_buf(void);
void func_80062920(void);
void func_80062978(s32 index, s32 arg1);
// void func_80062990();
// void func_800629AC();
// void func_800629C8();
// void func_800629E4();
void func_80062A08(s32 index);
void func_80062A24(s32 index);
// void func_80062A40();
bool func_80062A5C(s32 arg0);
bool func_80062A8C(s32 arg0);
bool func_80062AA8(s32 arg0);
bool func_80062AC4(s32 arg0);
// void func_80062AE0();
bool func_80062AFC(s32 arg0);
bool func_80062B18(s32 arg0);
bool func_80062B34(s32 arg0);
void func_80062B50(struct_watchGame_unk_9D0 *arg0, UNK_TYPE arg1, UNK_TYPE arg2, UNK_TYPE arg3, UNK_TYPE arg4, UNK_TYPE arg5, UNK_TYPE arg6);
void func_80062B84(struct_watchGame_unk_9D0 *arg0);
bool func_80062BC4(struct_watchGame_unk_9D0 *arg0);
bool timeAttackResult_update(struct_watchGame_unk_9D0 * arg0, s32 arg1);
void func_80062DA4(struct_watchGame_unk_9D0 * arg0);
s32 func_80062DD8(struct_watchGame_unk_9D0* arg0, UNK_TYPE arg1, UNK_TYPE arg2, UNK_TYPE arg3, UNK_TYPE arg4, UNK_TYPE arg5, UNK_TYPE arg6);
void func_80062E84(struct_watchGame_unk_0B8 *arg0);
void func_80062EC0(struct_watchGame_unk_0B8 *arg0);
void scoreNums_set(struct_watchGame_unk_0B8 *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4);
void backup_game_state(s32 index);
void resume_game_state(s32 index);
void func_80063378(void);
void func_800633C0(void);
void func_800633FC(void);
void dm_warning_h_line_se(void);
void dm_play_count_down_se(void);
void dm_capsel_down(struct_game_state_data *gameStateData, GameMapCell *mapCells);
s32 func_80063844(u32 arg0);
s32 dm_set_attack_2p(struct_game_state_data *gameStateDataRef);
s32 dm_set_attack_4p(struct_game_state_data *gameStateDataRef);
// void func_80063FF4();
// void save_visible_fall_point_flag();
void retryMenu_init(s32 arg0, s32 arg1);
// void func_8006417C();
s32 retryMenu_input(s32 arg0);
// void func_80064298();
// void func_8006431C();
void set_bottom_up_virus(struct_game_state_data *arg0, GameMapCell *mapCells);
bool bottom_up_bottle_items(GameMapCell *mapCells);
void add_taiQ_bonus_wait(struct_game_state_data *arg0);
bool func_80064848(void);
// void dm_game_eep_write_callback();
void func_80064940(void *arg0);
bool func_8006498C(s32 storyLevel, s32 storyNumber, s32 arg2);
void dm_save_all(void);
void dm_query_pause_player(struct_game_state_data *arg0);
s32 dm_game_main_cnt_1P(struct_game_state_data *arg0, GameMapCell *mapCells, s32 arg2);
s32 dm_game_main_cnt(struct_game_state_data *gameStateDataRef, GameMapCell *mapCells, s32 index);
// void func_800666FC();
// void func_80066808();
void dm_set_pause_and_volume(struct_game_state_data **gameStateDataP, s32 arg1);
void func_800669A0(struct_game_state_data *arg0);
void dm_calc_big_virus_pos(struct_game_state_data *arg0);
s32 dm_game_main_1p(void);
// void func_8006729C();
// void func_800673FC();
// void func_800674EC();
// void func_800675C8();
// void func_80067668();
s32 dm_game_main_2p(void);
s32 dm_game_main_4p(void);
bool dm_game_demo_1p(void);
bool dm_game_demo_2p(void);
bool dm_game_demo_4p(void);
struct TiTexData *dm_game_get_capsel_tex(s32 arg0); // void dm_game_get_capsel_tex();
struct TiTexData *dm_game_get_capsel_pal(s32 arg0, s32 arg1);
// void scoreNums_draw();
void func_80069160(struct_watchGame_unk_070 *arg0, UNK_TYPE *arg1, UNK_TYPE *arg2);
void func_80069188(struct_watchGame_unk_070 *arg0, s32 arg1);
void starForce_draw(struct_watchGame_unk_070* arg0, Gfx** gfxP, s32 arg2);
void func_800695A8(Gfx **gfxP, s32 arg1, s32 arg2, s32 arg3);
// void draw_4p_attack_guide_panel();
// void dm_map_draw();
// void func_80069ACC();
void draw_virus_number(Gfx **gfxP, u32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5);
void draw_count_number(Gfx **gfxP, s32 arg1, s32 arg2, u32 arg3, s32 arg4, s32 arg5);
void func_8006A098(Gfx **gfxP, u32 arg1, s32 arg2, s32 arg3);
void draw_time2(Gfx **gfxP, u32 arg1, s32 arg2, s32 arg3);
void push_any_key_draw(s32 arg0, s32 arg1);
void draw_demo_logo(Gfx **gfxP, s32 arg1, s32 arg2);
void draw_replay_logo(Gfx **gfxP, s32 arg1, s32 arg2);
void func_8006A938(s32 arg0);
void _disp_coin_logo(Gfx **gfxP, s32 arg1);
// void draw_flash_virus_light();
// void draw_flash_virus_lights();
// void func_8006AEFC();
void draw_story_board(Gfx **gfxP, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void draw_vsmode_board(Gfx **gfxP, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void _draw_bottle_10(Gfx **gfxP, s32 *arg1, s32 *arg2, s32 arg3);
void dm_calc_bottle_2p(void);
void dm_draw_bottle_2p(Gfx **gfxP);
void dm_draw_big_virus(Gfx **gfxP);
void dm_draw_KaSaMaRu(Gfx **gfxP, Mtx **mtxP, Vtx **vtxP, bool messageIsSpeaking, s32 arg4, s32 arg5, s32 arg6, u32 alpha);
// void dm_game_graphic_common();
void dm_game_graphic_p(struct_game_state_data *gameStateData, s32 arg1, GameMapCell *mapCells);
void dm_game_graphic_1p(struct_game_state_data *gameStateDataRef, s32 arg1, GameMapCell* mapCells);
void dm_game_graphic_effect(struct_game_state_data*gameStateDataRef, s32 arg1, s32 arg2);
void func_8006D0E8(void);
void dm_make_key(void);
void key_control_main(struct_game_state_data *gameStateDataRef, GameMapCell *mapCells, s32 arg2, s32 arg3);
void make_ai_main();
void dm_effect_make(void);
void dm_game_init_heap(void);
void dm_game_init(bool arg0);
void dm_game_init_static(void);
void dm_game_init_snap_bg(void);
void dm_game_draw_snap_bg(Gfx **gfxP, Mtx **mtxP, Vtx **vtxP, UNK_TYPE arg3);
void func_8006F628(Gfx **gfxP);
enum_main_no dm_game_main(struct NNSched *sc);
s32 dm_game_main2(void);
enum_main_no dm_game_main3(UNK_TYPE arg0);
void dm_game_graphic(void);
void dm_game_graphic2(void);
void dm_game_graphic_onDoneSawp(void);
void func_80071A44(void);
enum_main_no main_techmes(struct NNSched *sc);
void graphic_techmes(void);

extern struct_gameGeom *gameGeom;

#endif
