package hello;

import org.springframework.messaging.handler.annotation.*;
import org.springframework.stereotype.annotation.*;

@Controller
public class GreetingController {

  @MessageMapping("/hello")
  @SendTo("/topic/greetings")
  public Greeting greeting(HelloMessage message) throws Exception {
    Thread.sleep(1000); // simulated delay
    return new Greeting("Hello, " + message.getName() + "!");
  }
}
