package net.arhar.testplugin;

import org.bukkit.command.Command;
import org.bukkit.command.CommandSender;
import org.bukkit.plugin.java.JavaPlugin;

public class TestPlugin extends JavaPlugin {
    @Override
    public void onEnable() {
        getLogger().info("\n\n==============[ TestPlugin Enabled ]================\n\n");
    }
    
    @Override
    public void onDisable() {
        getLogger().info("\n\n==============[ TestPlugin Disabled ]================\n\n");
    }
    
    @Override
    public boolean onCommand(CommandSender sender, Command cmd, String label, String[] args) {
        getLogger().info("TestPlugin server intercepted command: " + cmd.getName());
        
        sender.sendMessage("TestPlugin intercepted command: " + cmd.getName());
        
        if (cmd.getName().equalsIgnoreCase("asdf")) {
            sender.sendMessage("you typed asdf!");
            
            return true;
        }
        
        return false;
    }
}