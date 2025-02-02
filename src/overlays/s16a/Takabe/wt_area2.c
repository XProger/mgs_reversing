#include "libgcl/libgcl.h"
#include "libgv/libgv.h"
#include "Game/game.h"

typedef struct WaterArea2Work
{
    GV_ACT  actor;
    int     where;        //0x20
    int     name;         //0x24
    SVECTOR bound[2];     //0x28
    char    field_38;     //0x38
    char    field_39;     //0x39
    char    field_3A;     //0x3A
    char    field_3B;     //0x3B
    int     snake_catch;  //0x3C
    int     splash_flag;  //0x40
    int     field_44;     //0x44
    int     field_48;     //0x48
    int     field_4C;     //0x4C
    int     proc_id;      //0x50
} WaterArea2Work;

extern int              THING_Gcl_GetInt( int o );
extern int              THING_Msg_CheckMessage( unsigned short name, int n_message, short *mes_list );
extern void             NewSplash2_800DB6F0( int angy, SVECTOR *pos, int noripple );
extern void            *NewRipple_800D7F30( MATRIX *, int );
extern void            *NewWaterView_800DBE04( int name, int where, int argc, char **argv );

extern unsigned int     GM_PlayerStatus_800ABA50;
extern int              GM_GameOverTimer_800AB3D4;
extern CONTROL         *GM_PlayerControl_800AB9F4;
extern OBJECT          *GM_PlayerBody_800ABA20;
extern SVECTOR          GM_NoisePosition_800AB9F8;
extern int              GM_NoiseLength_800ABA30;
extern int              GM_NoisePower_800ABA24;

//OPEN_MES, CLOSE_MES
unsigned short mes_list_800C3410[] = { 0x43D3, 0x4235 };
SVECTOR mouth_offset_800C3414 = { 0, 0, 100, 0 };

int WaterArea2BoundInCheck_800CEA48(SVECTOR *bound, SVECTOR *check)
{
    if ( !(check->vx <= bound[0].vx)  )
    {
        if ( check->vx < bound[1].vx )
        {
            if ( !(check->vy <= bound[0].vy) )
            {
                if ( check->vy < bound[1].vy )
                {
                    if ( !(check->vz <= bound[0].vz) )
                    {
                        if ( !(check->vz >= bound[1].vz) )
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

void WaterArea2ExecProc_800CEAD8(int proc_id, int mode)
{
    GCL_ARGS args;
    long     data;

    data = mode;

    if (proc_id == 0)
    {
        return;
    }

    args.argc = 1;
    args.argv = &data;
    GCL_ExecProc_8001FF2C(proc_id, &args);
}

void WaterArea2Act_800CEB10(WaterArea2Work *work)
{
    SVECTOR snake_pos;
    SVECTOR snake_floor;
    int     flag;
    MATRIX *eye;
    MATRIX *world;

    /* メッセージチェック */
    switch ( THING_Msg_CheckMessage( ( unsigned short )work->name, 2, mes_list_800C3410 ) ){
        case 0:
        /* 水しぶき有効 */
        work->splash_flag = 1 ;
        break ;
        case 1:
        /* 水しぶき無効 */
        work->splash_flag = 0 ;
        break ;
    }

    if ( GM_PlayerControl_800AB9F4 == NULL ) return ;

    snake_floor = GM_PlayerControl_800AB9F4->field_0_mov ;
    snake_floor.vy -= GM_PlayerControl_800AB9F4->field_32_height / 2;

    flag = WaterArea2BoundInCheck_800CEA48( work->bound, &snake_floor );

    if (!work->snake_catch)
    {
        if (flag)
        {
            snake_pos = snake_floor;
            snake_pos.vy = work->bound[1].vy;

            if (work->splash_flag)
            {
                NewSplash2_800DB6F0( GM_PlayerControl_800AB9F4->field_8_rot.vy + 2048, &snake_pos, 0 );
                work->splash_flag = 0;
            }

            GM_SeSet_80032858(&snake_pos, 176);

            if (work->field_44 == 0)
            {
                GM_SetNoise(0x64, 2, &snake_pos);
            }

            work->snake_catch = 1;
        }
    }
    else if (!flag)
    {
        snake_pos = snake_floor;
        snake_pos.vy = work->bound[1].vy;

        if (work->field_44 == 0)
        {
            GM_SetNoise(0x64, 2, &snake_pos);
        }

        work->snake_catch = 0;
    }

    if (GM_PlayerStatus_800ABA50 & 0x42)
    {
        world = &GM_PlayerBody_800ABA20->objs->objs[0].world;
    }
    else
    {
        world = &GM_PlayerBody_800ABA20->objs->objs[6].world;
    }

    snake_pos.vx = world->t[0];
    snake_pos.vy = world->t[1];
    snake_pos.vz = world->t[2];

    flag = WaterArea2BoundInCheck_800CEA48( work->bound, &snake_pos );

    if (!work->field_48)
    {
        if (flag)
        {
            WaterArea2ExecProc_800CEAD8( work->proc_id, 0x2A74 );
            work->field_48 = 1;
        }
    }
    else if ( !flag && !GM_GameOverTimer_800AB3D4 )
    {
        DG_SetPos2_8001BC8C( &snake_pos, &GM_PlayerControl_800AB9F4->field_8_rot );
        DG_PutVector_8001BE48( &mouth_offset_800C3414, &snake_pos, 1 );
        GM_SeSet_80032858( &snake_pos, 0xB3 );
        WaterArea2ExecProc_800CEAD8( work->proc_id, 0xF26E );
        work->field_48 = 0;
    }

    eye = &DG_Chanl(0)->field_30_eye;
    snake_pos.vx = eye->t[0];
    snake_pos.vy = eye->t[1];
    snake_pos.vz = eye->t[2];

    flag = WaterArea2BoundInCheck_800CEA48( work->bound, &snake_pos );

    if ( !work->field_4C )
    {
        if ( flag )
        {
            GM_SeSet2_80032968( 0, 0x3F, 0xB2 );
            WaterArea2ExecProc_800CEAD8( work->proc_id, 0xF6D8 );
            work->field_4C = 1;
        }
    }
    else if ( !flag )
    {
        GM_Sound_80032C48( 0xFF0000FE, 0 );
        WaterArea2ExecProc_800CEAD8( work->proc_id, 0xBED3 );
        work->field_4C = 0;
    }

    if ((GM_NoisePower_800ABA24 == 0xFF) &&
        (GM_NoiseLength_800ABA30 == 0x1F) &&
        WaterArea2BoundInCheck_800CEA48(work->bound, &GM_NoisePosition_800AB9F8))
    {
        GM_Sound_800329C4(&GM_NoisePosition_800AB9F8, 0xB5, 1);
    }
}

void WaterArea2Die_800CEF64(WaterArea2Work *work)
{
}

int WaterArea2GetResources_800CEF6C( WaterArea2Work *work, int name, int where )
{
    work->field_38 = 0x64;
    work->field_39 = 0x80;
    work->field_3A = 0x78;

    if ( GCL_GetOption_80020968( 'b' ) )
    {
        GCL_StrToSV_80020A14( GCL_Get_Param_Result_80020AA4(), &work->bound[0] );
        GCL_StrToSV_80020A14( GCL_Get_Param_Result_80020AA4(), &work->bound[1] );
    }

    if ( GCL_GetOption_80020968( 'c' ) )
    {
        work->field_38 = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
        work->field_39 = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
        work->field_3A = GCL_StrToInt_800209E8(GCL_Get_Param_Result_80020AA4());
    }

    work->field_44 = THING_Gcl_GetInt('s');
    work->proc_id  = THING_Gcl_GetInt('e');

    NewWaterView_800DBE04( name, where, (int)work->bound, (char **)&work->field_38 );
    return 0;
}

void *NewWaterArea2_800DACCC( int name, int where, int argc, char **argv )
{
    WaterArea2Work *work ;

    work = (WaterArea2Work *)GV_NewActor_800150E4( 5, sizeof( WaterArea2Work ) ) ;
    if ( work != NULL ) {
        GV_SetNamedActor_8001514C( &( work->actor ), ( TActorFunction )WaterArea2Act_800CEB10, ( TActorFunction )WaterArea2Die_800CEF64, "wt_area2.c" );
        if ( WaterArea2GetResources_800CEF6C( work, name, where ) < 0 )
        {
            GV_DestroyActor_800151C8( &( work->actor ) );
            return NULL;
        }
        work->where = where;
        work->name  = name;
    }
    return (void *)work ;
}
