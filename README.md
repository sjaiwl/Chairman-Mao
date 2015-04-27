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
