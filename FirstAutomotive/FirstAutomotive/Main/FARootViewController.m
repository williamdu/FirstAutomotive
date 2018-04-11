//
//  FARootViewController.m
//  FirstAutomotive
//
//  Created by liyi on 2018/4/11.
//  Copyright © 2018年 yiqin. All rights reserved.
//

#import "FARootViewController.h"

@interface FARootViewController ()

@end

@implementation FARootViewController

- (void)viewDidLoad {
    [super viewDidLoad];

}

- (void)viewDidAppear:(BOOL)animated {
    
    [super viewDidAppear:animated];
    
    NSString *segueID;
    // 登录
    segueID = @"Login";
    // 填写资料
//    segueID = @"Information";
    // 首页
    segueID = @"FATabBarController";
    
    [self performSegueWithIdentifier:segueID sender:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
