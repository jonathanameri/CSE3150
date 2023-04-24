// light bulb problem as taught in class. Don't change this class
class LightBulb
{
public:
  LightBulb() : isOn(false) {}
  bool IsOn() const { return isOn; }
  void SetOn(bool f) { isOn = f; }

private:
  bool isOn;
};

// Button class: abstract. Don't change this class
class Button
{
public:
  virtual void Push() = 0;
};

// a button for controlling lightbulb
class LightBulbButton : public Button
{
public:
  LightBulbButton(LightBulb &b) : bulb(b) {}

  void Push()
  {
    bulb.SetOn(!bulb.IsOn());
  }

private:
  LightBulb &bulb;
};
