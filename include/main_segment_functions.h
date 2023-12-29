#ifndef MAIN_SEGMENT_FUNCTIONS_H
#define MAIN_SEGMENT_FUNCTIONS_H

#include "libultra.h"
#include "libc/stdint.h"
#include "libc/stdbool.h"
#include "PR/sched.h"
#include "unknown_structs.h"
#include "unk.h"
#include "rom_offsets.h"
#include "gamemap.h"

struct TiTexData;


void func_80029ED0(struct_800EB670 *arg0, u8 viModeIndex, u8 retraceCount);
OSMesgQueue *func_8002A0CC(struct_800EB670 *arg0, UNK_PTR arg1);
OSMesgQueue *func_8002A0D4(struct_800EB670 *arg0);
void func_8002A0DC(void *arg);
void func_8002A184(struct_800EB670 *arg0, struct_800FAF98_unk_64 *arg1, OSMesgQueue *arg2);
void func_8002A1DC(struct_800EB670 *arg0, struct_800FAF98_unk_64 *arg1);
void func_8002A26C(struct_800EB670 *arg0, OSMesg msg);
void func_8002A2B8(void * arg);
void func_8002A3F4(struct_800EB670 *arg0, struct_800EB670_unk_66C *arg1);
void func_8002A4D8(void *arg);
void func_8002A51C(struct_800EB670 *arg0, struct_800EB670_unk_66C *arg1);

void func_8002BD20(s32 red, s32 green, s32 blue, s32 alpha, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void load_TexPal(TexturePtr tlut);
void func_8002BF90(TexturePtr tlut, u32 pal);
void load_TexBlock_4b(TexturePtr texture, s32 width, s32 height);
void func_8002C1E8(TexturePtr texture, s32 width, s32 height);
void load_TexTile_4b(TexturePtr texture, s32 width, s32 height, s32 uls, s32 ult, s32 lrs, s32 lrt);
void func_8002C4EC(TexturePtr texture, s32 width, s32 height);
// void func_8002C688();
void draw_Tex(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
// void func_8002C914();
// void func_8002CA68();
// void func_8002CD08();
// void func_8002CF04();

// void func_80038EF0();
// void func_8003901C();
// void func_800393DC();
// void func_800394A0();
// void func_8003974C();
// void func_80039BE0();
// void func_80039D08();
void *func_80039E14(void *arg0);
s32 func_80039F74(void);
void func_8003A1B4(Gfx **gfxP);
void *func_8003A26C(void *arg0);
s32 func_8003A618(void);
void func_8003A7E4(Gfx **gfxP);
void *func_8003A89C(void *arg0, s32 arg1);
s32 func_8003A8F4(void);
void func_8003A950(Gfx **gfxP);

f32 func_80045DD0(f32 arg0, f32 arg1);
f32 func_80045E18(f32 arg0, f32 arg1);
f32 func_80045E48(f32 arg0);
// void func_80045E94();
void transFunc_curve(MenuItem *item);
void transFunc_finger(MenuItem *item);
// void func_80046008();
void scaleFunc_curve(MenuItem *item);
// void func_800460DC();
void colorFunc_curve(MenuItem *item);
void colorFunc_cursor(MenuItem * /*item*/);
void menuItem_init(MenuItem *item, UNK_TYPE xPos, UNK_TYPE yPos);
void menuItem_updateTransScale(MenuItem *item, MenuItem *parent);
void menuItem_updateColor(MenuItem *item, MenuItem *parent);
void func_800464BC(MenuItem *item, MenuItem *parent);
void func_800464F8(MenuItem items[], s32 count, MenuItem *parent);
void func_8004655C(MenuItem *item, s32 arg1);
void func_800465B8(MenuItem *item, s32 arg1);
void func_80046614(MenuItem *item, s32 arg1);
;
void func_80046670(MenuItem *item, f32 arg1, f32 arg2);
void func_8004667C(MenuItem *item, f32 arg1, f32 arg2);
void func_80046688(MenuItem *item, f32 arg1, f32 arg2);
void func_80046694(MenuItem *item, f32 arg1, f32 arg2);
void func_800466A0(MenuItem *item, f32 arg1, f32 arg2);
void func_800466B8(MenuItem *item, f32 arg0, f32 arg1);
void func_800466D0(MenuItem *item);
void func_80046734(MenuItem *item, f32 arg0, f32 arg1, f32 arg2);
void func_800467E0(MenuItem *item);
void func_80046844(MenuItem *item, Gfx **gfxP);
bool menuItem_outOfScreen(MenuItem *item, s32 arg1, s32 arg2);
bool menuItem_drawTex(MenuItem *item, Gfx **gfxP, struct TiTexData *arg2, s32 arg3);
bool func_80046C74(MenuItem *item, Gfx **gfxP, struct TiTexData *arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
bool menuItem_drawAlphaTex(MenuItem *item, Gfx **gfxP, struct TiTexData * arg2, struct TiTexData * arg3, s32 arg4);
bool func_80046F58(MenuItem *item, Gfx **gfxP, struct TiTexData * arg2, s32 arg3, s32 arg4, s32 arg5);
// void func_80047074();
bool func_8004714C(MenuItem *item, Gfx **gxfP, struct TiTexData *arg2, struct TiTexData *arg3, s32 arg4, s32 arg5, s32 arg6);
// void func_800472D0();
void func_80047420(struct_watchMenu_unk_02548 *arg0, MainMenuMode arg1);
void func_800474EC(struct_watchMenu_unk_02548 *arg0, struct_watchMenu *watchMenuRef, UNK_TYPE arg2, UNK_TYPE arg3);
void func_80047584(struct_watchMenu_unk_02548 *arg0, MenuItem *item);
void menuTitle_draw(struct_watchMenu_unk_02548 *arg0, Gfx **gfxP);
void func_80047720(MenuCursor *cursor, s32 arg1, s32 arg2);
void func_800477BC(MenuCursor *cursor, s32 arg1, s32 arg2);
void menuCursor_init2(MenuCursor *cursor, struct_watchMenu *watchMenuRef, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                      s32 arg7, s32 arg8, s32 arg9);
void func_800479A8(MenuCursor *cursor, struct_watchMenu *watchMenuRef, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void menuCursor_update(MenuCursor *cursor, MenuItem *arg1);
void menuCursor_draw1(MenuCursor *cursorArr[], s32 count, Gfx **gxfP);
void menuCursor_draw2(MenuCursor *cursorArr[], s32 count, Gfx **gxfP);
void func_80048634(MenuCursor *cursorArr[], s32 /*count*/, Gfx **gxfP);
void func_80048680(MenuBottle *bottle, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3);
void func_800486C8(MenuBottle *bottle, MenuItem *arg1);
void menuBottle_draw(MenuBottle *bottle, Gfx **gxfP);
void func_80048B8C(MenuLvGauge *lvGauge, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_80048C48(MenuLvGauge *lvGauge, s32 arg1);
void func_80048CC8(MenuLvGauge *arg0, MenuItem *arg1);
void menuLvGauge_draw1(MenuLvGauge *lvGaugeP[], s32 count, Gfx **gxfP);
void func_80048FA0(MenuLvGauge *lvGaugeP[], s32 count, Gfx **gxfP);
// void func_80049034();
void func_80049080(MenuYN *yn, s32 arg1, f32 arg2);
// void func_800490B8();
void menuYN_init(MenuYN *yn, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3);
// void func_80049224();
void func_800492D8(MenuYN *yn, MenuItem *parentItem);
void menuYN_draw(MenuYN *yn, Gfx **gfxP);
void func_80049540(MenuMes *mes, s32 arg1, f32 arg2);
// void func_80049578();
void menuMes_init(MenuMes *mes, struct_watchMenu *watchMenuRef, struct_watchMenu_unk_02470 ** arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_8004970C(MenuMes *mes, const char *arg1);
void func_80049754(MenuMes *mes, MenuItem *parentItem);
void func_800497D0(MenuMes *mes, Gfx **gfxP);
void func_80049894(MenuSpeedAsk *arg0, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5);
void func_800498C4(MenuSpeedAsk *arg0, MenuItem *arg1);
void menuSpeedAsk_draw(MenuSpeedAsk *speedAskP[], s32 count, Gfx **gxfP);
void menuSpeedItem_init(MenuSpeedItem *speedItem, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void func_80049C54(MenuSpeedItem *speedItem, s32 arg1);
void menuSpeedItem_update(MenuSpeedItem *arg0, MenuItem *arg1);
void menuSpeedItem_draw1(MenuSpeedItem **speedItemP, s32 count, Gfx **gfxP);
void func_8004A160(MenuSpeedItem *speedItemP[], s32 count, Gfx **gxfP);
// void func_8004A1F4();
void menuMusicItem_init(MenuMusicItem *musicItem, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3, s32 arg4);
void menuMusicItem_input(MenuMusicItem *menuMusicItem, s32 arg1);
void menuMusicItem_update(MenuMusicItem *menuMusicItem, MenuItem *arg1);
void menuMusicItem_draw1(MenuMusicItem *musicItemArr[], s32 count, Gfx **gxfP);
void menuMusicItem_draw2(MenuMusicItem *musicItemArr[], s32 count, Gfx **gxfP);
void func_8004A814(MenuMusicItem *musicItemArr[], s32 arg1, Gfx **gfxP);
void func_8004A860(MenuNumber *arg0, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6);
void menuNumber_update(MenuNumber *menuNumber, MenuItem *item);
void menuNumber_draw(MenuNumber *numberP[], s32 arg1, Gfx **gxfP);
void func_8004AC98(MenuComLvPanel *comLvPanel, s32 arg1, f32 arg2);
void func_8004ACF4(MenuComLvPanel *comLvPanel, s32 arg1);
// void func_8004AD10();
void func_8004AD3C(MenuComLvPanel *arg0, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3, s32 arg4);
void func_8004AD84(MenuComLvPanel *comLvPanel, MenuItem *parent);
void menuComLvPanel_draw(MenuComLvPanel *comLvPanelP[], s32 count, Gfx **gfxP);
void menuCont_setFade(MenuCont *cont, s32 arg1, f32 arg2);
void func_8004B2C8(MenuCont *cont, s32 arg1, s32 arg2);
void menuCont_init(MenuCont *cont, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3);
// void func_8004B43C();
void func_8004B488(MenuCont *cont, MenuItem *parentItem);
void menuCont_draw(MenuCont *cont, Gfx **gfxP);
void func_8004B774(MenuMainPanel *mainPanel, s32 arg1, f32 arg2);
void menuMainPanel_init(MenuMainPanel *mainPanel, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3, const s32 *arg4, s32 arg5, s32 arg6);
// void func_8004B8CC();
void func_8004B98C(MenuMainPanel *arg0, MenuItem *parentItem);
void menuMainPanel_draw(MenuMainPanel *arg0, Gfx **gfxP);
void func_8004BB14(MenuNameSelPanel *nameSelPanel, s32 arg1, f32 arg2);
void menuNameSelPanel_clear(MenuNameSelPanel *nameSelPanel, bool arg1, s32 arg2);
void menuNameSelPanel_init(MenuNameSelPanel *nameSelPanel, struct_watchMenu *watchMenuRef, bool arg2, s32 arg3,
                           s32 arg4, s32 arg5);
// void func_8004BEB4();
// void func_8004BF10();
// void func_8004C1F0();
void menuNameSelPanel_update(MenuNameSelPanel *nameSelPanel, MenuItem *parentItem);
void menuNameSelPanel_draw(MenuNameSelPanel *nameSelPanel, Gfx **gfxP);
void func_8004C820(MenuNameOpPanel *nameOpPanel, s32 arg1, f32 arg2);
void menuNameOpPanel_init(MenuNameOpPanel *nameOpPanel, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3, const u8 *arg4, s32 xPos, s32 yPos);
// void func_8004C974();
void func_8004CA30(MenuNameOpPanel *nameOpPanel, MenuItem *parentItem);
void menuNameOpPanel_draw(MenuNameOpPanel *nameOpPanel, Gfx **gfxP);
void func_8004CCD0(MenuSndSelPanel *sndSelPanel, s32 arg1, f32 arg2);
void menuSndSelPanel_init(MenuSndSelPanel *sndSelPanel, struct_watchMenu *watchMenuRef, s32 arg2, s32 arg3,
                          s32 arg4);
// void func_8004CE48();
void func_8004CFB8(MenuSndSelPanel *sndSelPanel, MenuItem *parentItem);
void menuSndSelPanel_draw(MenuSndSelPanel *sndSelPanel, Gfx **gfxP);
void func_8004D258(void *arg);
void menuPlay2Panel_init(MenuPlay2Panel *play2Panel, struct_watchMenu *watchMenuRef, struct_watchMenu_unk_02470 **arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, bool arg7, CharAnimeMode arg8, s32 arg9, s32 argA, s32 argB, s32 argC);
void menuPlay2Panel_copyConfig(MenuPlay2Panel *play2Panel, MenuPlay2Panel *arg1);
void menuPlay2Panel_copyCursor(MenuPlay2Panel *play2Panel, MenuPlay2Panel *other);
// void func_8004D828();
void menuPlay2Panel_update(MenuPlay2Panel *play2Panel, MenuItem *parentItem);
void menuPlay2Panel_draw(MenuPlay2Panel *play2PanelArr[], s32 count, Gfx **gfxP);
void func_8004E270(MenuPlay2PanelSub *play2PanelSub, s32 arg1, f32 arg2);
// void func_8004E2B4();
void menuPlay2PanelSub_init(MenuPlay2PanelSub *play2PanelSub, struct_watchMenu *watchMenuRef,
                            struct_watchMenu_unk_02470 ** arg2, s32 arg3, s32 arg4, s32 arg5,
                            s32 arg6);
// void func_8004E4F4();
void menuPlay2PanelSub_update(MenuPlay2PanelSub *play2PanelSub, MenuItem *parentItem);
void menuPlay2PanelSub_draw(MenuPlay2PanelSub *play2PanelSub, Gfx **gfxP);
bool menuMain_setMsgStr(MenuMain *menuMain, MainMenuMode mode, s32 arg2);
void menuMain_initPanel(MenuMain *menuMain, MainMenuMode mode, s32 arg2, s32 arg3);
void menuMain_init(MenuMain *menuMain, struct_watchMenu *watchMenuRef, struct_watchMenu_unk_02470 **arg2);
void func_8004F2D8(MenuMain *menuMain);
// void func_8004F33C();
void menuMain_input(MenuMain *menuMain);
void menuMain_update(MenuMain *menuMain);
void menuMain_drawKaSaMaRu(MenuMain *menuMain, Gfx **gfxP);
void menuMain_draw(MenuMain *menuMain, Gfx **gfxP);
void func_800513F0(s32 arg0, s32 arg1, s32 arg2, s32 *xP, s32 *yP);
void func_80051480(MenuStory *menuStory, s32 arg1, f32 arg2);
void func_800514C4(void *arg);
void menuStory_init(MenuStory *menuStory, struct_watchMenu *watchMenuRef, struct_watchMenu_unk_02470 **arg2);
void func_80051974(MenuStory *menuStory);
// void func_800519CC();
// void func_800519EC();
void menuStory_input(MenuStory *menuStory);
void menuStory_update(MenuStory *menuStory);
void menuStory_draw(MenuStory *menuStory, Gfx **gfxP);
void func_800529FC(MenuLvSel *menuLvSel, s32 arg1, f32 arg2);
void menuLvSel_init(MenuLvSel *menuLvSel, struct_watchMenu *watchMenuRef, struct_watchMenu_unk_02470 **arg2);
void func_80052DF0(MenuLvSel *menuLvSel);
void menuLvSel_input(MenuLvSel *menuLvSel);
void menuLvSel_update(MenuLvSel *menuLvSel);
void menuLvSel_draw(MenuLvSel *menuLvSel, Gfx **gfxP);
void func_8005380C(MenuChSel *menuChSel, s32 arg1, f32 arg2);
void menuChSel_init(MenuChSel *menuChSel, struct_watchMenu *watchMenuRef, struct_watchMenu_unk_02470 **arg2);
bool menuChSel_checkSelected(MenuChSel *menuChSel, s32 arg1, s32 arg2, s32 arg3);
bool func_80053C84(MenuChSel *menuChSel, s32 arg1, s32 arg2);
void menuChSel_input1(MenuChSel *menuChSel, s32 arg1, s32 arg2);
void menuChSel_inputMan(MenuChSel *menuChSel);
void menuChSel_inputCom(MenuChSel *menuChSel);
void menuChSel_input(MenuChSel *menuChSel);
void menuChSel_update(MenuChSel *menuChSel);
void menuChSel_draw(MenuChSel *menuChSel, Gfx **gfxP);
void func_80054A94(MenuPlay2 *menuPlay2, s32 arg1, f32 arg2);
void menuPlay2_init(MenuPlay2 *menuPlay2, struct_watchMenu *watchMenuRef, struct_watchMenu_unk_02470 **arg2);
void func_800550F4(MenuPlay2 *menuPlay2);
// void func_80055154();
void func_800551BC(MenuPlay2 *menuPlay2, s32 /*index*/);
void func_80055254(MenuPlay2 *menuPlay2, s32 arg1);
// void func_800552EC();
// void func_80055598();
void menuPlay2_input(MenuPlay2 *menuPlay2);
void menuPlay2_update(MenuPlay2 *menuPlay2);
void menuPlay2_draw(MenuPlay2 *menuPlay2, Gfx **gfxP);
void func_80055DFC(MenuNmEnt *menuNmEnt, s32 arg1, f32 arg2);
void menuNmEnt_init(MenuNmEnt *menuNmEnt, struct_watchMenu *watchMenuRef, struct_watchMenu_unk_02470 **arg2);
// void func_800560D4();
void menuNmEnt_input(MenuNmEnt *menuNmEnt);
void menuNmEnt_update(MenuNmEnt *menuNmEnt);
void menuNmEnt_draw(MenuNmEnt *menuNmEnt, Gfx **gfxP);
// void func_80056C84();
void func_80056CAC(MenuRankBase *arg0, MenuItem *arg1);
void menuRankBase_draw(MenuRankBase **, s32 count, Gfx **gfxP);
// void func_80056DF0();
void func_80056E1C(MenuRankNum *arg0, MenuItem *arg1);
void menuRankNum_draw(MenuRankPanel **, s32 count, Gfx **gfxP);
// void func_80057014();
void menuRankFig_update(MenuRankFig *arg0, MenuItem *arg1);
void menuRankFig_draw(MenuRankFig ** arg0, s32 count, Gfx **gfxP);
// void func_8005768C();
void func_80057724(MenuRankName *arg0, MenuItem *arg1);
void menuRankName_draw(MenuRankName **, s32 count, Gfx **gfxP);
// void func_80057898();
void func_800578C8(MenuRankLabel *arg0, MenuItem *arg1);
void menuRankLabel_draw(MenuRankLabel **arg0, s32 count, Gfx **gfxP);
// void func_80057AFC();
void func_80057BE8(MenuRankHeader *arg0, MenuItem *arg1);
void menuRankHeader_draw(MenuRankLabel **arg0, s32 count, Gfx **gfxP);
// void func_80057D24();
// void func_80057E68();
// void func_80057F6C();
// void func_8005806C();
// void func_800581C8();
void menuRankPanel_update(MenuRankPanel *arg0, MenuItem *arg1);
void menuRankPanel_draw(MenuRankPanel **arg0, s32 count, Gfx **gfxP);
void menuRank_setNameBaseScale(MenuRank *menuRank, UNK_TYPE arg1, f32 arg2);
void menuRank_setSlide(MenuRank *menuRank, UNK_TYPE arg1, UNK_TYPE arg2, f32 arg3, f32 arg4);
void menuRank_setFrame(MenuRank *menuRank, UNK_TYPE arg1, UNK_TYPE arg2, f32 arg3);
// void func_80058A24();
void menuRank_setPanel(MenuRank *menuRank, s32 arg1, MainMenuMode arg2, UNK_TYPE arg3);
void menuRank_init(MenuRank *menuRank, struct_watchMenu *watchMenuRef, struct_watchMenu_unk_02470 **arg2);
void menuRank_input(MenuRank *menuRank);
void menuRank_update(MenuRank *menuRank);
void menuRank_draw(MenuRank *menuRank, Gfx **gfxP);
// void func_800599E0();
// void func_80059A58();
// void func_80059AA4();
// void func_80059AF0();
// void func_80059B5C();
// void func_80059BC8();
// void func_80059C34();
void func_80059CA0(struct_watchMenu *watchMenuRef);
Mtx **_getMtxPtr(struct_watchMenu *watchMenuRef);
Vtx **_getVtxPtr(struct_watchMenu *watchMenuRef);
struct TiTexData *_getTexChar(struct_watchMenu *watchMenuRef, s32 index);
struct TiTexData *_getTexCommon(struct_watchMenu *arg0, s32 arg1);
// void func_80059D14();
struct TiTexData *_getTexLevel(struct_watchMenu *watchMenuRef, s32 index);
struct TiTexData *_getTexMain(struct_watchMenu *watchMenuRef, s32 /*index*/);
// void _getTexName();
struct TiTexData *_getTexP2(struct_watchMenu *watchMenuRef, s32 index);
struct TiTexData *_getTexP4(struct_watchMenu *watchMenuRef, s32 index);
struct TiTexData *_getTexRank(struct_watchMenu *watchMenuRef, s32 /*index*/);
struct TiTexData *_getTexSetup(struct_watchMenu *watchMenuRef, s32 index);
// void func_80059D94();
// void func_80059DA4();
// void func_80059DB4();
// void func_80059DC4();
// void func_80059DD4();
struct TiTexData *_getTexKasa(struct_watchMenu *watchMenuRef, s32 index);
MenuItem *_getRootItem(struct_watchMenu *watchMenuRef);
u16 _getKeyLvl(struct_watchMenu *watchMenuRef, s32 arg1);
u16 _getKeyTrg(struct_watchMenu *watchMenuRef, s32 arg1);
u16 _getKeyRep(struct_watchMenu *watchMenuRef, s32 arg1);
MainMenuMode _getMode(struct_watchMenu *watchMenuRef);
MainMenuMode _getModeOld(struct_watchMenu *watchMenuRef);
void _setMode(struct_watchMenu *watchMenuRef, MainMenuMode arg1);
void _setNextMain(struct_watchMenu *watchMenuRef, enum_main_no arg1);
void menuTitle_setTitle(struct_watchMenu *watchMenuRef, MainMenuMode arg1);
void _setFadeDir(struct_watchMenu *watchMenuRef, s32 arg1);
void menuAll_init(struct_watchMenu *arg0, UNK_PTR *arg1, struct_800EB670 *arg2);
void func_8005A2AC(struct_watchMenu *arg0);
void func_8005A2EC(struct_watchMenu *arg0);
void menuAll_changeMenu(struct_watchMenu *arg0);

void menuAll_input(struct_watchMenu *arg0);
void menuAll_update(struct_watchMenu *arg0);
void menuAll_drawBg(struct_watchMenu *arg0, Gfx **gfxP);
void menuAll_draw(struct_watchMenu *arg0, Gfx **gfxP);
enum_main_no main_menu(struct_800EB670 * arg0);
void graphic_menu(void);

s32 fontStr_nextChar(const unsigned char *arg0);
s32 fontStr_length(const unsigned char *arg0);
s32 fontStr_charSize(const unsigned char *arg0, s32 arg1);
u16 func_8005B8D8(u8 arg0);
s32 font2index(const unsigned char *arg0);
void ascii2index(s32 character, s32 arg1, s32 *indexP, s32 *sizeP);
void font16_initDL(Gfx **gfxP);
void font16_initDL2(Gfx **gfxP);
void fontXX_draw(Gfx **gfxP, f32 x, f32 y, f32 width, f32 height, const unsigned char *arg5);
bool fontXX_drawID(Gfx **gfxP, f32 x, f32 y, f32 width, f32 height, s32 index);
bool fontXX_draw2(Gfx **gfxP, f32 arg1, f32 arg2, f32 arg3, f32 arg4, const unsigned char *arg5);
bool fontXX_drawID2(Gfx **gfxP, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
bool fontAsc_draw(Gfx **gfxP, f32 arg1, f32 arg2, f32 arg3, f32 arg4, const unsigned char * arg5);
bool fontAsc_drawID(Gfx **gfxP, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
bool fontAsc_draw2(Gfx **gfxP, f32 arg1, f32 arg2, f32 arg3, f32 arg4, const unsigned char * arg5);
bool fontAsc_drawID2(Gfx **gfxP, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);

void init_map_all(GameMapCell *mapCells);
void clear_map(GameMapCell *mapCells, s32 column, s32 row);
void clear_map_all(GameMapCell *mapCells);
s32 get_map_info(GameMapCell *mapCells, s32 column, s32 rowPlusOne); // TODO: cleanup bool comparisons
// void func_8005F09C();
// void func_8005F0E4();
s32 get_virus_color_count(GameMapCell *mapCells, u8 *arg1, u8 *arg2, u8 *arg3);
s32 get_virus_count(GameMapCell *mapCells);
void set_map(GameMapCell *mapCells, s32 column, s32 rowPlusOne, s32 arg3, s32 arg4);
void set_virus(GameMapCell *mapCells, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
u16 func_8005F2B0(void);
u32 func_8005F310(struct_virus_map_data *virusMapData, s32 arg1, s32 arg2);
bool dm_check_color(struct_virus_map_data *virusMapData, u16 arg1, u16 arg2, u8 arg3);
bool dm_check_color_2(struct_virus_map_data *virusMapData, u16 arg1, u16 arg2, u8 arg3);
void dm_virus_map_copy(struct_virus_map_data *virusMapSrc, struct_virus_map_data *virusMapDst, struct_virus_map_disp_order *virusDispOrderSrc, struct_virus_map_disp_order *virusDispOrderDst);
s32 dm_get_first_virus_count(enum_evs_gamemode evsGamemode, struct_game_state_data *arg1);
s32 dm_get_first_virus_count_in_new_mode(s32 arg0);
void _dm_virus_init(enum_evs_gamemode arg0, struct_game_state_data *arg1, struct_virus_map_data *virusMapData, struct_virus_map_disp_order *arg3, UNK_TYPE arg4);
void dm_virus_init(enum_evs_gamemode arg0, struct_game_state_data *arg1, struct_virus_map_data *virusMapData, struct_virus_map_disp_order *arg3);
void func_8005FC6C(struct_8005FC6C_arg0 *arg0, struct_virus_map_data *virusMapData, struct_virus_map_disp_order *virusMapDispOrder, s32 virusCount);
void _makeFlash_checkOrdre(struct_8005FC6C_arg0 *arg0);
// void func_8005FE68();
UNK_TYPE make_flash_virus_pos(struct_game_state_data *gameStateDataRef, struct_virus_map_data *virusMapData, struct_virus_map_disp_order *virusMapDispOrder);
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
void dm_set_virus(struct_game_state_data *gameStateDataRef, GameMapCell *mapCells, struct_virus_map_data *virusMapData,
                  struct_virus_map_disp_order *virusMapDispOrder);
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
void func_8006D620();
void dm_effect_make(void);
void dm_game_init_heap(void);
void dm_game_init(bool arg0);
void dm_game_init_static(void);
void dm_game_init_snap_bg(void);
void dm_game_draw_snap_bg(Gfx **gfxP, Mtx **mtxP, Vtx **vtxP, UNK_TYPE arg3);
void func_8006F628(Gfx **gfxP);
enum_main_no dm_game_main(struct_800EB670 *arg0);
s32 dm_game_main2(void);
enum_main_no dm_game_main3(UNK_TYPE arg0);
void dm_game_graphic(void);
void dm_game_graphic2(void);
void dm_game_graphic_onDoneSawp(void);
void func_80071A44(void);
enum_main_no main_techmes(struct_800EB670 * arg0);
void graphic_techmes(void);

// void func_80075F30();
enum_main_no dm_title_main(struct_800EB670 *arg0);
void dm_title_graphic(void);
enum_main_no main_boot_error(struct_800EB670 *arg0);
void graphic_boot_error(void);

UNK_TYPE lws_anim(Gfx **gfxP, Mtx *mtx, UNK_PTR arg2, UNK_TYPE arg3, UNK_PTR arg4);

f32 func_8007BC20(f32 arg0);
// void func_8007BC54();
// void func_8007BD30();
// void func_8007BEEC();
// void func_8007BFE0();
// void func_8007C0C4();
// void func_8007C244();
// void func_8007C480();
s16 angleF2S(f32 arg0);
// void func_8007C4D8();
// void func_8007C540();
// void func_8007C5A8();
// void func_8007C624();
// void func_8007C6D8();
// void func_8007C780();
// void func_8007C7E8();
// void func_8007C894();
// void func_8007C9C8();
// void func_8007CAFC();
// void func_8007CBE4();
// void func_8007CC68();
// void func_8007CCFC();
// void func_8007CD78();
// void func_8007CFB4();
void randomize00(void);
void randomseed(s32 seed);
s32 irandom(void);
s32 random(s32 arg0);

// void func_8007D260();
// void func_8007D348();
// void func_8007D410();
// void func_8007D4CC();
// void func_8007D568();
// void func_8007D644();
// void func_8007D74C();
// void func_8007D83C();
// void func_8007DB78();
// void func_8007DD70();
// void func_8007DF64();

void func_8007E260(struct_8007E260_arg0 *arg0, struct_8007E260_arg1 *arg1, struct_8007E260_arg2 *arg2);

u8 *func_8007E760(char *dst, u8 arg1, u8 arg2, u8 arg3, u32 arg4, u16 arg5, u8 *arg6);

// void func_8007EA20();
// void func_8007EA38();
// void func_8007EA58();
// void func_8007EAEC();
// void func_8007EC54();
// void func_8007EC98();
// void matrixMulL();
void makeTransrateMatrix(Mtx *mtx, u32 x, u32 y, u32 z);
void makeScaleMatrix(Mtx *mtx, u32 scale);
// void makeMatrix();
// void matrixConv();
// void func_8007F720();

// void func_8007F890();
// void func_8007F990();
// void func_8007F9D0();
// void func_8007FA00();
// void func_8007FB4C();
// void func_8007FDE4();
// void func_8007FE10();
// void func_8007FE40();
// void func_80080090();
// void func_80080110();
// void func_80080228();
// void func_800802F4();
// void func_80080374();
// void func_80080428();
// void func_80080480();
// void func_800804E0();
// void func_80080550();
// void func_800805C0();
// void func_8008064C();
// void func_800806D4();
// void func_80080710();
// void func_80080738();
// void func_8008075C();
// void func_80080768();
// void func_800807C4();
// void func_800807E8();
// void func_80080810();
// void func_80080840();
// void func_8008089C();
// void func_80080920();
// void func_80080928();
// void func_80080934();
// void func_80080940();
// void func_8008094C();
// void func_80080954();
// void func_8008095C();
// void func_80080968();
// void func_800809CC();
// void func_80080A44();
// void func_80080A50();
// void func_80080AB4();
// void func_80080B34();
// void func_80080BCC();
// void func_80080EC4();
// void func_80081430();
// void func_800814BC();
// void func_80081620();
// void func_80081734();
// void func_800817A4();
// void func_80081980();
// void func_8008199C();
// void func_80081A54();
// void func_80081AAC();
// void func_80081B10();
// void func_80081BD4();
// void func_80081CE8();
// void func_80081E7C();
// void func_80082014();
// void func_800820A8();
// void func_800821E4();
// void func_800823AC();
// void func_800823E4();
// void func_80082494();
// void func_8008263C();
// void func_800828A8();
// void func_800828FC();
// void func_8008291C();
// void func_8008294C();
// void func_8008296C();
// void func_80082978();
// void func_80082AA0();
// void func_80082B84();
// void func_80082B98();
// void func_80082BBC();
// void func_80082C2C();
// void func_80082CA0();
// void func_80082CB0();
// void func_80082CE0();
// void func_80082CF0();
// void func_80082D00();
// void func_80082D10();
// void func_80082D68();
// void func_80082D78();
// void func_80082D84();
// void func_80082D94();
// void func_80082DA0();
// void func_80082E0C();
// void func_80082EA8();
// void func_80082ED0();
// void func_80082EDC();
// void func_80082EEC();
// void func_80082EF8();
// void func_80082F0C();
// void func_80082F20();
// void func_80082F28();
// void func_80082F70();
// void func_80082F7C();
// void func_80082F84();
// void func_80082FF4();
// void func_80083004();
// void func_80083054();
// void func_800830A4();
// void func_800830F4();
// void func_80083104();
// void func_800831D4();
// void func_80083210();
// void func_80083220();
// void func_80083264();
// void func_800832D4();
// void func_800832E0();
// void func_80083338();
// void func_80083604();
// void func_80083698();
// void func_800837E4();
// void func_80083AC4();
// void func_80083ADC();
// void func_80083B20();
// void func_80083B64();
// void func_80083BC0();
// void func_80083D34();
// void func_80083E04();
// void func_80083E10();
// void func_80083E7C();
// void func_80084020();
// void func_8008402C();
// void func_80084090();
// void func_800840F0();
// void func_800841D0();
// void func_80084308();
// void func_80084490();
// void func_800844DC();
// void func_8008450C();
// void func_80084524();
// void func_80084530();
// void func_8008455C();
// void func_800845D0();
// void func_800845D4();
// void func_80084648();

#if VERSION_CN
void func_8002B8B4_cn(void);
void func_8002B910_cn();
#endif

#if VERSION_CN || VERSION_GW
void func_8002BC30_cn(s32 arg0);
void func_8002BD04_cn(void);
#endif

#if VERSION_CN
void func_8002BA98_cn(s32 arg0, s32 arg1);

void func_8002BD7C_cn(Gfx **gfxP, s32 arg1, s32 arg2);
#endif


#endif
