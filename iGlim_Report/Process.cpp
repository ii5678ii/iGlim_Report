﻿// Process.cpp: 구현 파일
//

#include "pch.h"
#include "iGlim_Report.h"
#include "Process.h"


// CProcess

CProcess::CProcess()
{
}

CProcess::~CProcess()
{
}

int CProcess::getStarInfo(CImage * pImage, int nTh)
{
	unsigned char* fm = (unsigned char*)pImage->GetBits();
	int nWidth = pImage->GetWidth();
	int nHeight = pImage->GetHeight();
	int nPitch = pImage->GetPitch();

	int nSum = 0; 
	for (int k = 0; k < nWidth * nHeight; k++) {
		if (fm[k] > nTh)
			nSum++;
	}
	return nSum;
}


// CProcess 멤버 함수
