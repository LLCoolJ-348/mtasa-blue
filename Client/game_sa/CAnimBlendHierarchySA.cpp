/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/CAnimBlendHierarchySA.cpp
*  PURPOSE:     Animation blend hierarchy
*  DEVELOPERS:  Jax <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#include "StdInc.h"

// Careful, GetIndex will not work for custom animations
int CAnimBlendHierarchySAInterface::GetIndex ( void )
{
    return ( ( ( DWORD ) this - ARRAY_CAnimManager_Animations ) / 24 );
}

void CAnimBlendHierarchySA::Initialize ( void )
{
    m_pInterface->pSequences = 0;
    m_pInterface->usNumSequences = 0;
    m_pInterface->bRunningCompressed = 0;
    m_pInterface->pad = 0;
    m_pInterface->iAnimBlockID = -1;
    m_pInterface->fTotalTime = 0;
    m_pInterface->pLinkPtr = 0;
}

void CAnimBlendHierarchySA::SetName ( const char * szName ) 
{
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CAnimBlendHierarchy_SetName;
    _asm
    {
        push    szName
        mov     ecx, dwThis
        call    dwFunc
    }
}

void CAnimBlendHierarchySA::RemoveAnimSequences ( void )
{
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CAnimBlendHierarchy_RemoveAnimSequences;
    _asm
    {
        mov     ecx, dwThis
        call    dwFunc
    }
}

void CAnimBlendHierarchySA::RemoveFromUncompressedCache ( void )
{
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CAnimBlendHierarchy_RemoveFromUncompressedCache;
    _asm
    {
        mov     ecx, dwThis
        call    dwFunc
    }
}

void CAnimBlendHierarchySA::RemoveQuaternionFlips ( void )
{
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CAnimBlendHierarchy_RemoveQuaternionFlips;
    _asm
    {
        mov     ecx, dwThis
        call    dwFunc
    }
}

void CAnimBlendHierarchySA::CalculateTotalTime ( void )
{
    DWORD dwThis = ( DWORD ) m_pInterface;
    DWORD dwFunc = FUNC_CAnimBlendHierarchy_CalculateTotalTime;
    _asm
    {
        mov     ecx, dwThis
        call    dwFunc
    }
}

CAnimBlendSequenceSAInterface * CAnimBlendHierarchySA::GetSequence ( DWORD dwIndex )
{
    BYTE * pSequences = reinterpret_cast < BYTE * > ( m_pInterface->pSequences );
    return reinterpret_cast < CAnimBlendSequenceSAInterface * > ( pSequences +  ( sizeof ( CAnimBlendSequenceSAInterface ) * dwIndex ) );
}
