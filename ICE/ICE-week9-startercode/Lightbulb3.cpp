// light bulb problem as taught in class: don't change this class
class LightBulb
{
public:
  LightBulb() : isOn(false) {}
  bool IsOn() const { return isOn; }
  void SetOn(bool f) { isOn = f; }

private:
  bool isOn;
};

// Button class
class Button
{
public:
  Button(LightBulb &b) : bulb(b) {}
  void Push()
  {
    bulb.SetOn(!bulb.IsOn());
  }

private:
  LightBulb &bulb;
};
