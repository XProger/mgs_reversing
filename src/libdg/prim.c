#include "libdg.h"
#include "inline_n.h"
#include <GTEMAC.H>

extern int      GV_Clock_800AB920;
extern MATRIX   DG_ZeroMatrix_8009D430;

void DG_PrimStart_8001AC00()
{
}

void DG_8001AC08(DVECTOR *xy0, DVECTOR *xy1, DVECTOR *xy2, DVECTOR *xy3)
{
    int x0 = xy0->vx;
    int x1 = xy1->vx;
    int y0 = xy0->vy;
    int y1 = xy1->vy;
    int x1_x0_diff = x1 - x0;
    int y1_y0_diff = y1 - y0;

    if ( x1_x0_diff < 0 )
    {
        x1_x0_diff = -x1_x0_diff;
    }

    if ( y1_y0_diff < 0 )
    {
        y1_y0_diff = -y1_y0_diff;
    }

    if ( y1_y0_diff >= x1_x0_diff )
    {
        xy2->vx = x0 + 2;
        xy2->vy = y0;
        xy3->vx = x1 + 2;
        xy3->vy = y1;
    }
    else
    {
        xy2->vy = y0 + 1;
        xy2->vx = x0;
        xy3->vx = x1;
        xy3->vy = y1 + 1;
    }
}

void DG_8001AC74(DG_PRIM *pPrims, int prim_type)
{
    // TODO: Check if these prim types are actually correct when we have more context
    if ( prim_type == 21 )
    {
        int n_prims;
        POLY_FT4 *i = (POLY_FT4 *)pPrims->field_40_pBuffers[GV_Clock_800AB920];
        for (n_prims = (signed short)pPrims->n_prims ; n_prims > 0; --n_prims )
        {
            DG_8001AC08((DVECTOR *)&i->x0, (DVECTOR *)&i->x1, (DVECTOR *)&i->x2, (DVECTOR *)&i->x3);
            i++;
        }
    }
    else // prim_type == 22 ?
    {
        int n_prims;
        POLY_GT4 *i = (POLY_GT4 *)pPrims->field_40_pBuffers[GV_Clock_800AB920];
        for (n_prims = (signed short)pPrims->n_prims ; n_prims > 0; --n_prims )
        {
            DG_8001AC08((DVECTOR *)&i->x0, (DVECTOR *)&i->x1, (DVECTOR *)&i->x2, (DVECTOR *)&i->x3);
            i++;
        }
    }
}

SVECTOR* sub_8001AD28( SVECTOR *svec, int n_svec )
{
  int      i;
  SVECTOR *svec2;
  
  svec2 = (SVECTOR*)0x1F800000;

  for ( i = n_svec - 1 ; i >= 0 ; --i ) 
  {
    gte_ldv3c( svec );
    gte_rtpt();
    gte_stsxy3( &svec2[0].vx, &svec2[1].vx, &svec2[2].vx );
    gte_stsz3(  &svec2[0].vz, &svec2[1].vz, &svec2[2].vz );
    svec  += 3;
    svec2 += 3;
  }

  return svec;
}

char *DG_PrimChanl_helper_helper_8001ADA0( DG_PRIM* prim, char* ptr, int count )
{
    char* p;
    int t3, t2, t0, a0;
    SVECTOR* svec;
    count--;

    t3 = prim->field_30_prim_size;
    t0 = prim->field_32;
    t2 = prim->field_34;
    a0 = prim->field_36;

    svec = (SVECTOR*)0x1F800000;
    for ( ; count >= 0; --count )
    {
        p = ptr + t2;
        *(short*)ptr = svec->vz;

        switch( t0 )
        {
        case 4:
            LCOPY(svec, p);
            svec++;
            p += a0;
        case 3:
            LCOPY(svec, p);
            svec++;
            p += a0;
        case 2:
            LCOPY(svec, p);
            svec++;
            p += a0;
        case 1:
            LCOPY(svec, p);
            svec++;
        }
        ptr += t3;
    }
    return ptr;
}

void DG_PrimChanl_helper_8001AE5C( DG_PRIM *prim )
{
    SVECTOR *svec;
    unsigned char *prims;
    int count, s4, n_svec, n_prims;

    s4 = prim->field_32;    

    if ( s4 == 4 )
    {
        n_svec = 40;
        count  = 30;
    }
    else
    {
        n_svec = 42;
        count  = 126 / s4;
    }

    svec = prim->field_38_pUnknown;
    n_prims = prim->n_prims;
    prims = (unsigned char*)prim->field_40_pBuffers[ GV_Clock_800AB920 ];

    if ( count < n_prims )
    {
        do
        {
            svec = sub_8001AD28( svec, n_svec );
            prims = DG_PrimChanl_helper_helper_8001ADA0( prim, prims, count );
            n_prims -= count;
        } while ( count < n_prims );
    }

    sub_8001AD28( svec, ( ( n_prims * s4 ) + 2 ) / 3 );
    DG_PrimChanl_helper_helper_8001ADA0( prim, prims, n_prims );
}

char *DG_PrimChanl_helper2_helper_8001AF90( DG_PRIM* prim, char* ptr, int count )
{
    char* p;
    int prim_size, t2, t0, a0;
    int* t3;
    SVECTOR* svec;
    count--;

    prim_size = prim->field_30_prim_size;
    t0 = prim->field_32;
    t2 = prim->field_34;
    a0 = prim->field_36;

    svec = (SVECTOR*)0x1F800000;
    
    for ( ; count >= 0; --count )
    {
        t3 = (int*)0x1F8003F0;
        gte_NormalClip( *(int*)&svec[0].vx, *(int*)&svec[1].vx, *(int*)&svec[2].vx, 0x1F8003F0 );
        p = ptr + t2;
        
        if (*t3 <= 0)
        {
            *(short*)ptr = 0;
            svec += t0;
        }
        else
        {
            SCOPYL(&svec->vz, ptr);
            switch( t0 )
            {
            case 4:
                gte_stsxy0( p );
                p += a0;
                svec++;
            case 3:
                gte_stsxy1( p );
                p += a0;
                svec++;
            case 2:
                gte_stsxy2( p );
                p += a0;
                svec++;
            case 1:
                LCOPY( svec, p );
                svec++;
            }
        }        
        ptr += prim_size;
    }
    return ptr;
}

void DG_PrimChanl_helper2_8001B0B4( DG_PRIM *prim )
{
    SVECTOR *svec;
    unsigned char *prims;
    int count, s4, n_svec, n_prims;

    s4 = prim->field_32;    

    if ( s4 == 4 )
    {
        n_svec = 0x28;
        count  = 0x1E;
    }
    else
    {
        n_svec = 0x2A;
        count  = 126 / s4;
    }

    svec = prim->field_38_pUnknown; //s2    
    n_prims = prim->n_prims; //s1
    prims = (unsigned char*)prim->field_40_pBuffers[ GV_Clock_800AB920 ]; 

    if ( count < n_prims )
    {
        do
        {
            svec = sub_8001AD28( svec, n_svec );
            prims = DG_PrimChanl_helper2_helper_8001AF90( prim, prims, count );
            n_prims -= count;
        } while ( count < n_prims );
    }
    sub_8001AD28( svec, ((n_prims * s4) + 2) / 3 );
    DG_PrimChanl_helper2_helper_8001AF90( prim, prims, n_prims );
}

// read vecs from spad
char *sub_8001B1E8( DG_PRIM* prim, char* ptr, int count )
{
    //ptr = prim pointer
    RECT* rect;
    int prim_size;
    SVECTOR* svec;
    int rect_x, rect_y;

    rect = prim->field_3C;
    prim_size = prim->field_30_prim_size;
    rect_x = rect->x;
    rect_y = rect->y;

    svec = (SVECTOR*)0x1F800000;
    for ( --count ; count >= 0; --count )
    {
        *(short*)(ptr + 0x00) =  svec->vz;
        *(short*)(ptr + 0x08) = (svec->vx - rect_x);
        *(short*)(ptr + 0x0A) = (svec->vy - rect_y);
        
        svec++;
        ptr += prim_size;
    }

    return ptr;
}

// scratch pad memory max size in bytes
#define SPAD_SIZE 1024

// how many SVECTORS we can fit in the scratch pad bar one
#define MAX_SPAD_SVECTORS (int)(SPAD_SIZE / sizeof(SVECTOR)) - 1

// how many SVECTORS to process each iteration
#define BATCH_SIZE (MAX_SPAD_SVECTORS - 1)

void DG_8001B254(DG_PRIM *pDGPrim)
{
    SVECTOR *pVec = pDGPrim->field_38_pUnknown;
    int      n_prims = (signed short)pDGPrim->n_prims;
    short   *pPrims = (short *)pDGPrim->field_40_pBuffers[GV_Clock_800AB920];

    // Process in batches if too big to fit in the scratch pad in one go
    if (n_prims >= MAX_SPAD_SVECTORS)
    {
        pVec = pDGPrim->field_38_pUnknown;
        do
        {
            pVec = sub_8001AD28(pVec, BATCH_SIZE / 3);
            pPrims = (short*)sub_8001B1E8(pDGPrim, (char*)pPrims, BATCH_SIZE);
            n_prims -= BATCH_SIZE;
        } while (n_prims >= MAX_SPAD_SVECTORS);
    }

    sub_8001AD28(pVec, (n_prims + 2) / 3);
    sub_8001B1E8(pDGPrim, (char*)pPrims, n_prims);
}

char *DG_PrimChanl_helper3_helper_8001B31C( DG_PRIM* prim, char* ptr, int count )
{
    char    *p;
    RECT    *rect;
    SVECTOR *svec;
    SVECTOR *svec_last;
    VECTOR  *vec;
    VECTOR  *vec_inner;
    int neg_x, neg_y, prim_size, t7, t1, i;
    SVECTOR local_svec[2];

    i = count;
    rect = prim->field_3C;

    neg_x = -rect->x;
    local_svec[0].vx = neg_x;
    neg_y = -rect->y;
    local_svec[0].vy = neg_y;
    local_svec[0].vz = 0;

    local_svec[1].vx = rect->w + neg_x;
    local_svec[1].vy = rect->h + neg_y;
    local_svec[1].vz = 0;

    gte_ldv01c ( local_svec );
    gte_SetRotMatrix( &DG_ZeroMatrix_8009D430 );

    vec = (VECTOR*)0x1F8003F0;
    svec = (SVECTOR*)0x1F800000;
    svec_last = (SVECTOR*)0x1F8003D8;
    prim_size = prim->field_30_prim_size;
    t7 = prim->field_34;
    t1 = prim->field_36;

    vec->vy = 0;
    vec->vx = 0;

    gte_SetGeomOffset( svec->vx , svec->vy );
    vec->vz = *(int*)&svec->vz;
    gte_SetTransVector( 0x1F8003F0 );
    gte_rtpt();

    svec++;
    gte_stsxy01( &svec_last->vx , &svec_last->vz );
    
    for ( --i ; i >= 0; --i )
    {
        vec_inner = (VECTOR*)0x1F8003F0;
        gte_SetGeomOffset( svec->vx , svec->vy );
        vec_inner->vz = *(int*)&svec->vz;
        gte_SetTransVector( 0x1F8003F0 );
        gte_rtpt();


        p = ptr + t7;
        *(short*)ptr = svec[-1].vz;
        svec++;

        *(long*)p = *(long*)&svec_last->vx; 

        p += t1;
        *(short*)(p + 0) = svec_last->vz;
        *(short*)(p + 2) = svec_last->vy;

        p += t1;
        *(short*)(p + 0) = svec_last->vx;
        *(short*)(p + 2) = svec_last->pad;

        ptr += prim_size;
        p += t1;
        *(long*)p = *(long*)&svec_last->vz;

        gte_stsxy01( &svec_last->vx , &svec_last->vz );
    }

    gte_SetGeomOffset(0,0);
    return ptr;
}


// how many SVECTORS we can fit in the scratch pad bar four
#define MAX_SPAD_SVECTORS2 (int)(SPAD_SIZE / sizeof(SVECTOR))-4 

// how many SVECTORS to process each iteration
#define BATCH_SIZE2 (MAX_SPAD_SVECTORS2-1)

void DG_PrimChanl_helper3_8001B534(DG_PRIM *pDGPrim)
{
    SVECTOR *pVec = pDGPrim->field_38_pUnknown;
    int n_prims = (signed short)pDGPrim->n_prims;
    unsigned char *pPrims = (unsigned char*)pDGPrim->field_40_pBuffers[GV_Clock_800AB920];
    
    // Process in batches if too big to fit in the scratch pad in one go
    if (n_prims >= MAX_SPAD_SVECTORS2)
    {
        pVec = pDGPrim->field_38_pUnknown;
        do
        {
            pVec = sub_8001AD28(pVec, BATCH_SIZE2 / 3);
            pPrims = DG_PrimChanl_helper3_helper_8001B31C(pDGPrim, pPrims, BATCH_SIZE2);
            n_prims -= BATCH_SIZE2;
        } while (n_prims >= MAX_SPAD_SVECTORS2);
    }

    sub_8001AD28(pVec, (n_prims + 2) / 3);
    DG_PrimChanl_helper3_helper_8001B31C(pDGPrim, pPrims, n_prims);
}

void DG_8001B5FC(DG_PRIM *pPrim)
{
    int               n_prims = pPrim->n_prims;
    union Prim_Union *prim_buffer = pPrim->field_40_pBuffers[GV_Clock_800AB920];
    sub_8001AD28(pPrim->field_38_pUnknown, pPrim->field_48_prim_count);
    pPrim->field_50_pFn((struct DG_PRIM *)pPrim, prim_buffer, n_prims);
}