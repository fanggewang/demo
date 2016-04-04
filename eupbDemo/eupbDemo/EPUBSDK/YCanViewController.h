#import <UIKit/UIKit.h>

//page information
@interface  PageInformation: NSObject
@property NSString*           chapterName;
@property NSInteger           chapterIndex;
@property NSInteger           pageNumInChapter;
@property NSInteger           pageNumInBook;
@property NSInteger           totalPagesCountInChapter;
@end

//================================================================
//draw extra information 
@protocol YcanPageViewDrawExtraDelegate <NSObject>
@optional
-(void)drawRect:(CGRect)rect pageInfo:(PageInformation*)pageInfo;
@end

//================================================================
//show outline
@interface  OutlineData: NSObject
@property    NSString*         refID;
@property    NSString*         title;
@property    NSURL*            contentURL;
@property    NSMutableArray*   child;
@end

//================================================================
@interface YCanViewController:UIViewController
@property (nonatomic,readwrite)CGRect    layoutBounds;
@property (nonatomic,readwrite)UIColor*  backgroundColor;
@property (readwrite)CGFloat             defaultTextSizeMultiplier;
@property (readwrite)CGFloat             defaultLineHeightMultiplier;
@property (nonatomic,readwrite)NSString* defaultFontFamily;
@property (readonly)NSInteger            totalPagesInBook;
@property (nonatomic, retain) NSArray*   outlineArray;
@property (nonatomic, retain) NSMutableDictionary*     chaptersInfo;
@property (nonatomic, readonly)PageInformation*        curPageInfo;
@property (nonatomic, weak) id<YcanPageViewDrawExtraDelegate> delegate;

+(NSString*)extractCoverFromEPUB:(NSString*)path toDir:(NSString*)destPath;
//open and close
-(int)openFile:(NSString*)path;

//navigation method
-(void)gotoURL:(NSURL*)URL;
-(void)gotoChapter:(NSUInteger)index andPos:(NSUInteger)pos;
-(void)getCurChapter:(NSUInteger*)index andPos:(NSUInteger*)pos;

//relayout after user change the settings
-(void)relayoutAllViews;
@end



