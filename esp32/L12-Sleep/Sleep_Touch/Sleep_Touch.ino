RTC_DATA_ATTR int count = 0;

void toccato() {}

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

  touch_pad_t pins = esp_sleep_get_touchpad_wakeup_status();
  switch (pins){
    case 0: Serial.println("GPIO 4"); break;
    case 1: Serial.println("GPIO 0"); break;
    case 2: Serial.println("GPIO 2"); break;
    case 3: Serial.println("GPIO 15"); break;
    case 4: Serial.println("GPIO 13"); break;
    case 5: Serial.println("GPIO 12"); break;
    case 6: Serial.println("GPIO 14"); break;
    case 7: Serial.println("GPIO 27"); break;
    case 8: Serial.println("GPIO 33"); break;
    case 9: Serial.println("GPIO 32"); break;
    default: Serial.println("GPIO ??");
  }

  touchAttachInterrupt(T2, toccato, 40);
  esp_sleep_enable_touchpad_wakeup();

  Serial.println("Sto per andare in sleep...");
  delay(1000);
  esp_deep_sleep_start();
  
}

void loop() {}
