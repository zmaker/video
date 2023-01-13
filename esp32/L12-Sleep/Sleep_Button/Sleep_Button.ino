RTC_DATA_ATTR int count = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  count++;
  Serial.print("\ncount: ");
  Serial.println(count);

  esp_sleep_wakeup_cause_t causa;
  causa = esp_sleep_get_wakeup_cause();
  switch (causa){
    case ESP_SLEEP_WAKEUP_EXT0:
      Serial.println("Button");
      break;
    case ESP_SLEEP_WAKEUP_TIMER:
      Serial.println("timer");
      break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD:
      Serial.println("Touch");
      break;
    default:
      Serial.println("??");
  }

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_14, 1);

  Serial.println("Sto per andare in sleep...");
  delay(1000);
  esp_deep_sleep_start();
  
}

void loop() {}
