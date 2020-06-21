# Soul-Knight 项目文档

> 同济大学2019年高级程序设计课程大项目

## 项目信息

- 项目选题： **元气骑士**

- 项目成员：
  -  杨鑫  1950787
  - 潘景祥 1953181
  - 余缨子 1952727
  - 吴一帆 1953214

- 小组成员贡献比例
  |  姓名  |                           分工                           | 贡献比例 |
  | :----: | :------------------------------------------------------: | :------: |
  |  杨鑫  |           交互设计，界面效果，素材收集，场景切换            |   100%   |
  | 潘景祥 |           游戏架构，角色设计，地图生成，小地图，雕像         |   100%   |
  | 余缨子 |           怪物设计，怪物AI，BOSS型敌人            |   100%   |
  | 吴一帆 |           武器，技能飞行物，宝箱，道具            |   100%   |

- 项目地址： <https://github.com/Shmiwy/soul-knight>

- 项目进度时间线
  - 2020-05-11
    - 选题元气骑士
    - 学习cocos2dx 3.x
  - 2020-05-20
    - 游戏架构基本完成
    - 人物类设计完成
  - 2020-05-24
    - 开始地图生成设计
  - 2020-05-30
    - 地图设计基本完善
    - 添加交界面交互
  - 2020-05-31
    - 设计敌人类以及敌人AI
  - 2020-06-01
    - 实现开始界面，安全、探险场景切换
    - 增加小地图
  - 2020-06-04
    - 实现人物8个方向移动
    - 增加人物主动技能
    - 增加音量调节
  - 2020-06-06
    - 增加武器类，实现子弹发射
  - 2020-06-07
    - 增加道具类
  - 2020-06-08
    - 增加人物移动动画
    - 实现人物拾捡武器、道具
  - 2020-06-09
    - 将敌人添加到战斗地图，并使其移动、攻击
     - 增加主角状态信息栏
     - 增加boss类
  - 2020-06-12
    - 实现人物护甲自动恢复
    - 增加敌人类型
  - 2020-06-13
    - 增加地图种类
    - 增加不同地图、不同敌人外观
  - 2020-06-17
    - 修复一些的bug
    - 增加雕像类以及buff
  - 2020-06-19
    - 实现雕像与人物交互
    - 增加金币系统
    - 增加金币、关卡显示
  - 2020-06-20
    - 增加敌人子弹
    - 增加宝箱
    2020-06-21
    - 完善，修复bug
    - 撰写项目文档，制作ppt

## 项目开发文档

- 选用引擎：**Cocos2d-x 3.17.2**

- 辅助软件：NULL

- 支持平台：Windows

- 小组分工：
  |  姓名  |                           分工                           | 贡献比例 |
  | :----: | :------------------------------------------------------: | :------: |
  |  杨鑫  |           交互设计，界面效果，素材收集，场景切换            |   100%   |
  | 潘景祥 |           游戏架构，角色设计，地图生成，小地图，雕像         |   100%   |
  | 余缨子 |           怪物设计，怪物AI，BOSS型敌人            |   100%   |
  | 吴一帆 |           武器，技能飞行物，宝箱，道具            |   100%   |

- 实现的功能点
  - 基础功能
    - [x] 游戏开始界面、背景音乐、音量控制、暂停及恢复功能、退出功能

    - [x] 键盘控制
      
      实现思路:
      - 通过cocos提供的键盘Listener实现
      - 按下w、a、s、d设置人物速度，从而实现人物移动
      - 按下j、k则会调用交互、攻击、大招函数
      
    - [x] 至少两类武器

      + 若怪物与骑士重合，按j则进行近身攻击
      + 若骑士持枪，按j发射子弹，每5发子弹后产生一次暴击，威力翻倍
      + 若骑士持剑，按j进行近身攻击
      + 宝箱可能出现枪或剑，按j则可以更换枪或剑

    - [x] 至少两种普通敌人类型

      实现思路:
      - setType设置敌人类型，不同敌人类型设置不同的ATTACKRANGE，以及对应不同的攻击函数，通过type的tag来控制调用哪个
      - 设置好类型之后，每一帧会调用aiOfEnemy函数，该函数会根据骑士和敌人的距离判断是该使用巡游函数、跟着骑士走还是调用攻击函数
      - 巡游函数就是通过判断是否会出界，选出可行方向，随机在可行方向里头挑一个，然后往那个方向走一定距离之后再次更改方向
      - 有一个总的攻击函数，它的作用就是通过type的tag来调用具体函数
      
    - [x] 至少两种道具，恢复生命、增加护甲、法力值

      + 宝箱可以刷出道具，在道具旁按j则可以使用道具
      + 打死一个场景所有小怪可得法力，杀死一个小怪可能获取一个金币也可能没有

    - [x] 安全地图与探险地图

    - [x] 宝箱机制，开启可获得武器或道具

      + 杀死一个场景所有小怪和boss，可随机获取一个宝箱，在武器房，会自动生成一个宝箱
      + 打怪生成得宝箱，40%啥都没有，10%出枪，10%出加血，10%出加蓝，10出加金币，20出加护具
      + 武器房宝箱，必得一把枪

    - [x] 关卡中主角死亡，探险终止并返回安全地图

    - [x] 至少两个关卡
      
      实现思路:
      - 判断人物与传送门的位置，通过Director::replaceScene函数生成下一关卡
      - 人物指针设为static，从而使人物信息在进入下一关卡时不变

  - 进阶功能
    - [x] 每次进入即使进入相同关卡也会有不同游戏地图、敌人、道具等
      
      实现思路:
      - 使用c++随机函数，从5*5的房间矩阵中随机选取联通的房间
      - 敌人数目类型，道具类型均随机生成
    - [x] 游戏小地图
      
      实现思路:
      - 使用cocos的DrawNode绘制小地图 以及用Color4F设置不同颜色
      - 战斗房间生成时对四个方向做上联通标记，用于生成小地图走廊
      - 探险地图根据人物位置更新地图信息
    - [ ] 多个可选主角
    - [x] buff机制(增加移速，增加或翻倍属性，翻倍伤害)
      
      实现思路:
      
      - 通过雕像触发实现，有血量、蓝量、护甲、伤害、移速buff
    - [ ] debuff机制(移动减速、中毒、流血、冰冻)
    - [x] 金兵机制
      - [ ] 主角等级系统，高等主角拥有更强的属性或能力，主角可通过消耗金币升级(安全地图中)
      - [ ] 安全地图中的商店系统，可在进入关卡前购买或抽取道具、武器等
      - [x] 探险地图中的老爷爷系统，可在关卡中购买/获赠礼物，如武器/道具/buff等
        
        实现思路:
        - 人物类增加 static int gold 成员，保证进入下一关卡金币数不变
        - 击杀怪物，打开宝箱设置为有一定几率获得金币
        - 通过与雕像的交互可以使用金币获得buff
    - [ ] 特殊地形(木墙、沼泽、岩浆、地刺)
  - [x] BOSS型敌人
    
      实现思路:
      - aiOfBoss用来控制boss移动攻击，boss一般时间不会追踪骑士，而是巡游，骑士离得太近了就会按照一定时间间隔进行扣血
      - boss每隔一定时间【定为3s】发一次大招，uniqueSkill函数控制大招，通过随机数从三个大招里头选一个。三个大招分别为随机加一定量的血，向骑士瞬移【有距离上限】以及一定范围内攻击
    - [x] 雕像
      
      实现思路:
      - 编写雕像类(继承Node)并在房间生成时添加雕像到类型为PROP的战斗房间
      - 雕像设了9中类型，每种类型对应不同图片以及buff加成
      - 雕像底座设为障碍物，人物不可穿越；雕像上半部分处于最上层，能遮盖人物
      - 当人物位于雕像正下方且按J时，雕像通过Label显示文字提示，金币足够则扣除金币获得buff，并标记为不可在访问

- C++功能及特性的使用
    - [x] STL容器(vector, queue)
    - [x] 迭代器
    - [x] 类和多态
    - [x] 类型推断
    - [x] 常量表达式(constexpr)
    - [x] Lambda表达式
    - [x] 字符串字面量

- 项目的技术难点
  - 地图的高度随机

    解决方案及过程:
    - 随机生成房间以及联通方式随机
      - 房间从5*5的房间矩阵中选取
      - 先选取一个起点，将其房间类型设为起点
      - 通过队列，从队首房间所能访问的房间(右，上，左，下)中随机选几个生成并做好连接标记(若房间已生成则仅做上连接标记)
      - 最后一个生成的房间设为终点并添加传送门; 若为BOSS关卡则房间变大，并添加BOSS，不设传送门
      - 对于道具和武器宝箱房间，从与起点不相连且不为终点的房间中选取即可
      - 最后通过dfs将房间通过走廊联通(生成走廊)
    - 地图类型的随机(森林， 火山， 地牢等)
      - BattleScene类中加入有 static vector<string> 成员，保存不同地图素材路径
      - BattleScene类添加 static int battleSceneNumber 成员记录关卡数
      - 使用randShuffle函数在进入探险地图前将vector随机打乱。
      - 每过五个小关卡，改变一次地图类型(如1-1，2-1， 3-1...)

- 项目运行截图
![](C:/Users/PC/Desktop/1.png)
![](C:/Users/PC/Desktop/2.png)
![](C:/Users/PC/Desktop/3.png)
![](C:/Users/PC/Desktop/4.png)