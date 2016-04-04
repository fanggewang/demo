//
//  ViewController.m
//  eupbDemo
//
//  Created by 王放歌 on 16/3/23.
//  Copyright © 2016年 WangFangGe. All rights reserved.
//

#import "ViewController.h"
#import "YCanViewController.h"
@interface ViewController ()
@property (nonatomic,strong)YCanViewController* bookViewController;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    // Do any additional setup after loading the view, typically from a nib.
    [self prepareUI];
    
}
- (void)prepareUI{
    _bookViewController = [[YCanViewController alloc] init];
    //_bookViewController.delegate = (id<YcanPageViewDrawExtraDelegate>)self;
    [self.view addSubview:_bookViewController.view];
    //[self.view bringSubviewToFront:toolBar];
    //[self.view bringSubviewToFront:settingPanelView];
    NSString *epubPath =@"/Users/wangfangge/Desktop/辩证唯物主义纲要副本.epub";
    //set background color
    //UIImage* backgroundImg = [UIImage imageNamed:@"readBg02.jpg"];
    [_bookViewController gotoChapter:0 andPos:0];
    _bookViewController.backgroundColor=[UIColor redColor];
    [_bookViewController openFile:epubPath];


}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
