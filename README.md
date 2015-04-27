# Chairman-Mao
基于C++语言，利用有限状态机机制，实现人物状态的转变。
## 十送红军的算法分析与设计
### 1.人物类的设计
主要设计了三个任务对象，Mao类，People类以及Guard类，Mao类是毛主席类，People类群众类，Guard类是侦察员类。
### 2.人物状态设计
* Mao的状态转换图<br>
  Mao的状态转移取决于接收的消息，无消息接收是处于WalkOnRoad状态，通过对消息的处理然后跳转到相应的状态。
![image](https://github.com/sjaiwl/image_folder/blob/master/chairMao/mao.png)
* People的状态转换图<br>
  People的状态跳转取决于随机函数，People个状态间随机跳转。
![image](https://github.com/sjaiwl/image_folder/blob/master/chairMao/people.png)
* Guard的状态转换图<br>
  Guard的状态跳转取决于延迟消息的发送与处理，进行状态间的跳转。
![image](https://github.com/sjaiwl/image_folder/blob/master/chairMao/guard.png)

## 代码实现
* 人物类的实现（以Mao类为例）
```
class Mao : public BaseGameEntity
{
private:
  StateMachine<Mao>*  m_pStateMachine;
public:
  Mao(int id);
  ~Mao(){delete m_pStateMachine;}
  void Update();
  StateMachine<Mao>*  GetFSM()const{return m_pStateMachine;}
  virtual bool  HandleMessage(const Telegram& msg);
};
```
* 2.状态类的实现（以MaoOwnedStates中两个接收消息的状态为例）
```
MaoGlobleState* MaoGlobleState::Instance()
{
  static MaoGlobleState instance;
  return &instance;
}
void MaoGlobleState::Enter(Mao* pMao){}
void MaoGlobleState::Execute(Mao* pMao){}
void MaoGlobleState::Exit(Mao* pMao){}
bool MaoGlobleState::OnMessage(Mao* pMao, const Telegram& msg)
{
	switch(msg.Msg)
  {
	  case Msg_GetReport:
   {
       cout << "\nMessage handled by " << GetNameOfEntity(pMao->ID()) << " at time: " 
       << Clock->GetCurrentTime();
     SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);
     cout << "\n" << GetNameOfEntity(pMao->ID()) << 
          ":ChairMao,report to you! ";
     pMao->GetFSM()->ChangeState(GetReport::Instance());
	return true;
   }
  }
  ......
```
* 消息系统的添加
  * 立即消息添加（以GuardOwnedStates为例）
  ```
  ReportToMao* ReportToMao::Instance()
{
  static ReportToMao instance;
  return &instance;
}
void ReportToMao::Enter(Guard* pGuard)
{
    SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pGuard->ID()) << ": " << "I run to Mao";
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
                              pGuard->ID(),        //ID of sender
                              ent_Chair_Mao,            //ID of recipient
                              Msg_GetReport,   //the message
                              NO_ADDITIONAL_INFO); 
}
......
```
  * 延迟消息添加（以GuardOwnedStates为例）
  ```
  CollectInformation* CollectInformation::Instance()
{
  static CollectInformation instance;
  return &instance;
}
void CollectInformation::Enter(Guard* pGuard)
{  
    SetTextColor(FOREGROUND_BLUE| FOREGROUND_INTENSITY);
    cout << "\n" << GetNameOfEntity(pGuard->ID()) << ": " << "I will go to collect    information";
	Dispatch->DispatchMessage(1.5,                  //time delay
                              pGuard->ID(),           //sender ID
                              pGuard->ID(),           //receiver ID
                              Msg_ReportToMao,        //msg
                              NO_ADDITIONAL_INFO);  
}
......
```
## 主函数调用
```
  Mao* mao=new Mao(ent_Chair_Mao);
  People* people=new People(ent_People);
  Guard* guard=new Guard(ent_Guard);
  EntityMgr->RegisterEntity(mao);
  EntityMgr->RegisterEntity(people);
  EntityMgr->RegisterEntity(guard);
  //simply run the miner through a few Update calls
  for(int i=0;i<15;i++)
  {
	people->Update();
	mao->Update();
	guard->Update();
	Dispatch->DispatchDelayedMessages();
	Sleep(800);
 } 
   delete mao;
   delete people;
   delete guard;
```

## 输出效果图
![image](https://github.com/sjaiwl/image_folder/blob/master/chairMao/test.png)
