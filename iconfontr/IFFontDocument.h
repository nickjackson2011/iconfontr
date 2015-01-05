//
//  IFDocument.h
//  iconfontr
//
//  Created by Chase Zhang on 4/12/14.
//  Copyright (c) 2014 io-meter. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <JNWCollectionView.h>

@interface IFFontDocument : NSDocument

@end
/*
 ---------------FFTM
 OS/2   // OS/2 and Windows specific metrics
 cmap   // Character to glyph mapping
 ---------------cvt    // Control value table
 ---------------fpgm   // Font program
 gasp   // Grid-fitting/Scan-conversion
 glyf   // Glyph data
 head   // Font header
 hhea   // Horizontal header
 hmtx   // Horizontal metrics
 loca   // Index to location
 maxp   // Maximum profile
 name   // Naming table
 post   // PostScript information
 ---------------prep   // CVT program
 
 
 cmap           字符代码到图元的映射      把字符代码映射为图元索引
 head           字体头                 字体的全局信息
 glyf           图元数据                图元轮廓定义以及网格调整指令
 maxp           最大需求表              字体中所需内存分配情况的汇总数据
 mmtx           水平规格                图元水平规格
 loca           位置表索引               把元索引转换为图元的位置
 name           命名表                  版权说明、字体名、字体族名、风格名等等
 hmtx           水平布局                 字体水平布局星系：上高、下高、行间距、最大前进宽度、最小左支撑、最小右支撑
 kerm           字距调整表               字距调整对的数组
 post           PostScript信息          所有图元的PostScript   FontInfo目录项和PostScript名
 PCLT           PCL   5数据              HP   PCL   5Printer   Language   的字体信息：字体数、宽度、x高度、风格、记号集等等
 OS/2           OS/2和Windows特有的规格   TrueType字体所需的规格集
 enum {
 kCTFontTableBASE    = 'BASE',   // Baseline
 kCTFontTableCFF     = 'CFF ',   // PostScript font program
 kCTFontTableDSIG    = 'DSIG',   // Digital signature
 kCTFontTableEBDT    = 'EBDT',   // Embedded bitmap
 kCTFontTableEBLC    = 'EBLC',   // Embedded bitmap location
 kCTFontTableEBSC    = 'EBSC',   // Embedded bitmap scaling
 kCTFontTableGDEF    = 'GDEF',   // Glyph definition
 kCTFontTableGPOS    = 'GPOS',   // Glyph positioning
 kCTFontTableGSUB    = 'GSUB',   // Glyph substitution
 kCTFontTableJSTF    = 'JSTF',   // Justification
 kCTFontTableLTSH    = 'LTSH',   // Linear threshold
 kCTFontTableMATH    = 'MATH',   // Math
 kCTFontTableOS2     = 'OS/2',   // OS/2 and Windows specific metrics
 kCTFontTablePCLT    = 'PCLT',   // PCL 5 data
 kCTFontTableVDMX    = 'VDMX',   // Vertical device metrics
 kCTFontTableVORG    = 'VORG',   // Vertical origin
 kCTFontTableZapf    = 'Zapf',   // Glyph reference
 kCTFontTableAcnt    = 'acnt',   // Accent attachment
 kCTFontTableAnkr    = 'ankr',   // Anchor points
 kCTFontTableAvar    = 'avar',   // Axis variation
 kCTFontTableBdat    = 'bdat',   // Bitmap data
 kCTFontTableBhed    = 'bhed',   // Bitmap font header
 kCTFontTableBloc    = 'bloc',   // Bitmap location
 kCTFontTableBsln    = 'bsln',   // Baseline
 kCTFontTableCmap    = 'cmap',   // Character to glyph mapping
 kCTFontTableCvar    = 'cvar',   // CVT variation
 kCTFontTableCvt     = 'cvt ',   // Control value table
 kCTFontTableFdsc    = 'fdsc',   // Font descriptor
 kCTFontTableFeat    = 'feat',   // Layout feature
 kCTFontTableFmtx    = 'fmtx',   // Font metrics
 kCTFontTableFpgm    = 'fpgm',   // Font program
 kCTFontTableFvar    = 'fvar',   // Font variation
 kCTFontTableGasp    = 'gasp',   // Grid-fitting/Scan-conversion
 kCTFontTableGlyf    = 'glyf',   // Glyph data
 kCTFontTableGvar    = 'gvar',   // Glyph variation
 kCTFontTableHdmx    = 'hdmx',   // Horizontal device metrics
 kCTFontTableHead    = 'head',   // Font header
 kCTFontTableHhea    = 'hhea',   // Horizontal header
 kCTFontTableHmtx    = 'hmtx',   // Horizontal metrics
 kCTFontTableHsty    = 'hsty',   // Horizontal style
 kCTFontTableJust    = 'just',   // Justification
 kCTFontTableKern    = 'kern',   // Kerning
 kCTFontTableKerx    = 'kerx',   // Extended kerning
 kCTFontTableLcar    = 'lcar',   // Ligature caret
 kCTFontTableLtag    = 'ltag',   // Language tags
 kCTFontTableLoca    = 'loca',   // Index to location
 kCTFontTableMaxp    = 'maxp',   // Maximum profile
 kCTFontTableMort    = 'mort',   // Morph
 kCTFontTableMorx    = 'morx',   // Extended morph
 kCTFontTableName    = 'name',   // Naming table
 kCTFontTableOpbd    = 'opbd',   // Optical bounds
 kCTFontTablePost    = 'post',   // PostScript information
 kCTFontTablePrep    = 'prep',   // CVT program
 kCTFontTableProp    = 'prop',   // Properties
 kCTFontTableSbit    = 'sbit',   // Bitmap data
 kCTFontTableSbix    = 'sbix',   // Extended bitmap data
 kCTFontTableTrak    = 'trak',   // Tracking
 kCTFontTableVhea    = 'vhea',   // Vertical header
 kCTFontTableVmtx    = 'vmtx'    // Vertical metrics
 };
 */