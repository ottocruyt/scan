#include "../ScanState/SettingUpScanState.h"
#include "Subscriptions.h"

int Observer::static_number_ = 0;

Subject::~Subject()
{
  std::cout << "Goodbye, I was the Subject.\n";
}

void Subject::Attach(IObserver *observer)
{
  list_observer_.push_back(observer);
}

void Subject::Detach(IObserver *observer)
{
  list_observer_.remove(observer);
}

void Subject::Notify()
{
  std::list<IObserver *>::iterator iterator = list_observer_.begin();
  while (iterator != list_observer_.end())
  {
    (*iterator)->Update(message_);
    (*iterator)->Update(subjectReady);
    ++iterator;
  }
}

void Subject::CreateMessage(std::string message)
{
  this->message_ = message;
  Notify();
}

void Subject::isReady(std::string message)
{
  this->message_ = message;
  this->subjectReady = true;
  Notify();

}

Observer::Observer(Subject &subject) : subject_(subject)
{
  this->subject_.Attach(this);
  std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
  this->number_ = Observer::static_number_;
}
Observer::~Observer()
{
  std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void Observer::Update(const std::string &message_from_subject)
{
  message_from_subject_ = message_from_subject;
  PrintInfo();
}
void Observer::Update(bool subjectReady)
{
  this->subjectReady = subjectReady;
  if(subjectReady && callbackOnReady != nullptr)
  {
    callbackOnReady->onComReady();
  }
}

void Observer::RemoveMeFromTheList()
{
  subject_.Detach(this);
  std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}

void Observer::PrintInfo()
{
  std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
}

void Observer::setCallbackOnReady(SettingUpScanState* state)
{
  callbackOnReady = state;
}