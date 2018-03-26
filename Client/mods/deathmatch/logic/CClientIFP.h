#pragma once

#ifndef __CCLIENTIFP_H
#define __CCLIENTIFP_H

#include "CClientEntity.h"
#include "IFP/IFPLoader.h"
#include "IFP/CIFPAnimations.h"
#include <algorithm>

class CClientIFP: public CClientEntity, FileLoader
{
public:
                                    CClientIFP              ( class CClientManager* pManager, ElementID ID );
                                    ~CClientIFP             ( void );

    virtual eClientEntityType       GetType                 ( void ) const              { return CCLIENTIFP; }

    const SString &                 GetBlockName            ( void ) { return m_strBlockName; }
    bool                            isIFPLoaded             ( void ) { return m_bisIFPLoaded; }
    bool                            LoadIFP                 ( const char* szFilePath, SString strBlockName );
    void                            UnloadIFP               ( void );

    bool                            LoadIFPFile(const char * FilePath);
    void                            ReadIFPVersion1();
    void                            ReadIFPVersion2( bool anp3);

    std::string                     convertStringToMapKey(char * String);
    IFP_FrameType                   getFrameTypeFromFourCC(char * FourCC);
    size_t                          GetSizeOfCompressedFrame ( IFP_FrameType FrameType );

    void                            ReadKrtsFramesAsCompressed (  BYTE * pKeyFrames, int32_t TotalFrames );
    void                            ReadKrt0FramesAsCompressed (  BYTE * pKeyFrames, int32_t TotalFrames );
    void                            ReadKr00FramesAsCompressed (  BYTE * pKeyFrames, int32_t TotalFrames );

    void                            InsertAnimationDummySequence ( std::unique_ptr < CAnimBlendSequence > & pAnimationSequence, std::string & BoneName, DWORD & BoneID );
    int32_t                         getBoneIDFromName(std::string const& BoneName);
    std::string                     getCorrectBoneNameFromName(std::string const& BoneName);
    std::string                     getCorrectBoneNameFromID(int32_t & BoneID);
    size_t                          getCorrectBoneIndexFromID(int32_t & BoneID);

    CAnimBlendHierarchySAInterface * GetAnimationHierarchy ( const SString & strAnimationName );
    inline std::shared_ptr < CIFPAnimations > GetIFPAnimationsPointer ( void ) { return m_pIFPAnimations; }

    // Sorta a hack that these are required by CClientEntity...
    void                            Unlink                  ( void ) {};
    void                            GetPosition             ( CVector& vecPosition ) const {};
    void                            SetPosition             ( const CVector& vecPosition ) {};

   
private:
    std::shared_ptr < CIFPAnimations > m_pIFPAnimations;
    SString                         m_strBlockName;
    std::vector < IFP_Animation > * m_pVecAnimations;
    std::vector < unsigned char * > m_DummySequencesKeyFrames;
    bool                            isVersion1;
    IFPHeaderV2                     HeaderV2;
    bool                            m_bisIFPLoaded;

};

#endif
