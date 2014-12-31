//
//  IFMagnifyCollectionView.h
//  iconfontr
//
//  Created by Chase Zhang on 4/15/14.
//  Copyright (c) 2014 io-meter. All rights reserved.
//

#import <JNWCollectionView.h>

typedef enum {
    NJMenuCodeCopySVGText = 0,
    NJMenuCodeCopySVGPath,
    NJMenuCodeCopyUnicode,
} NJMenuCode;

@interface IFMagnifyCollectionView : JNWCollectionView

- (NSString *)SVGContentForIndexPath:(NSIndexPath*)indexPath isPathString:(NSInteger)isPathString;

@end
