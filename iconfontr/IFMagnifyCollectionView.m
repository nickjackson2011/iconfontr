//
//  IFMagnifyCollectionView.m
//  iconfontr
//
//  Created by Chase Zhang on 4/15/14.
//  Copyright (c) 2014 io-meter. All rights reserved.
//

#import "IFMagnifyCollectionView.h"
#import "IFCollectionGridLayout.h"
#import "NSBezierPath+SVGPathString.h"
#import "IFCollectionGlyphCell.h"

#define kEqualsKeyCode 24
#define kMinusKeyCode 27

@interface IFMagnifyCollectionView ()
{
  IFCollectionGridLayout *_gridLayout;
}

@end

@implementation IFMagnifyCollectionView

- (void)awakeFromNib
{
  [super awakeFromNib];
  [self setAutohidesScrollers:YES];
  [self invokeMagnification];
  [self applyGridLayout];
}

- (void)applyGridLayout
{
  if (_gridLayout==nil) {
    _gridLayout = [[IFCollectionGridLayout alloc] init];
    _gridLayout.itemSize = NSMakeSize(100, 100);
    _gridLayout.allowsLiveLayout = YES;
    self.collectionViewLayout = _gridLayout;
  }
}

- (void)invokeMagnification
{
  if (!self.allowsMagnification) {
    self.allowsMagnification = YES;
    self.magnification = 1.0;
    self.maxMagnification = 3;
    self.minMagnification = 1.0;
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(liveMagnifyWillStart:)
                                                 name:NSScrollViewWillStartLiveMagnifyNotification
                                               object:self];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(liveMagnifyDidEnd:)
                                                 name:NSScrollViewDidEndLiveMagnifyNotification
                                               object:self];
  }
}

- (void)liveMagnifyWillStart:(NSNotification *)n
{
  _gridLayout.allowsLiveLayout = NO;
}

- (void)liveMagnifyDidEnd:(NSNotification *)n
{
  if (self.magnification<=1.01 || [self.documentView frame].size.width <= self.visibleSize.width - 10.0) {
    _gridLayout.allowsLiveLayout = YES;
    [self.collectionViewLayout invalidateLayout];
  }
  self.scrollerStyle = NSScrollerStyleOverlay;
}

- (void)keyDown:(NSEvent *)theEvent
{
  // cancel the sound played after keydown
}

- (void)keyUp:(NSEvent *)theEvent
{
  if ([theEvent keyCode]==kEqualsKeyCode) {
    self.magnification += 0.2;
  }
  else if([theEvent keyCode]==kMinusKeyCode) {
    self.magnification -= 0.2;
  }
}

- (void)layoutDocumentView {
	if (_gridLayout.allowsLiveLayout) {
    [super layoutDocumentView];
  }
}

#pragma mark - Actions
- (void)selectNone:(id)sender
{
  [self deselectAllItems];
}

- (void)copy:(id)sender
{
  NSArray * selectedItems = [self indexPathsForSelectedItems];
  if ([selectedItems count]) {
    NSIndexPath *lastSelected = [selectedItems lastObject];
    NSString *content = [self SVGContentForIndexPath:lastSelected isPathString:[sender tag]];
   if (content) {
      NSPasteboard * pasteboard = [NSPasteboard pasteboardWithName:NSGeneralPboard];
      [pasteboard clearContents];
      [pasteboard setString:content forType:NSPasteboardTypeString];
    }
  }
}

#pragma mark - Content to save

- (NSString *)SVGContentForIndexPath:(NSIndexPath*)indexPath isPathString:(NSInteger)isPathString
{
  IFCollectionGlyphCell *cell = (IFCollectionGlyphCell *)[self cellForItemAtIndexPath:indexPath];
  
  NSColor *fgcolor = cell.color;
  NSColor *bgcolor = self.backgroundColor;
  NSString *canvasStyle = [NSString stringWithFormat:@"background:%@", [NSBezierPath SVGColorStringWithColor:bgcolor]];
  NSString *pathStyle = [NSString stringWithFormat:@"fill:%@", [NSBezierPath SVGColorStringWithColor:fgcolor]];
    
    NSString *result = @"";
    switch (isPathString) {
        case NJMenuCodeCopySVGText:
        {
            result = [[cell.content bezierPath] SVGTextWithWidth:nil
                                                          height:nil
                                                     canvasStyle:canvasStyle
                                                       pathStyle:pathStyle];
        }
            break;
        case NJMenuCodeCopySVGPath:
        {
            result = [[cell.content bezierPath] SVGPathString];
        }
            break;
        case NJMenuCodeCopyUnicode:
        {
            //TODO: 添加返回unicode的代码
            id<IFIconModel> theCellContent = cell.content;
            NSString *theUnicode = [theCellContent unicode];
            const char *theChar = [theUnicode cStringUsingEncoding:NSUnicodeStringEncoding];
            result = [NSString stringWithFormat:@"\\u%04x", *theChar];
            NSLog(@"%@", result);
            NSLog(@"%@", [NSString stringWithFormat:@"\\u%04x", *[theUnicode cStringUsingEncoding:NSUTF8StringEncoding]]);//\ue600
        }
            break;
            
        default:
            break;
    }
    
    return result;
}

@end
