# Flawless Abbey Developer Task made by Kelson Wysocki

*A built version for Windows is in the ProjectBuild directory.*

## Inventory system
### Design
I made an item class inherited from an interactable actor class (later also used for dialogue).
Each item has a type that distinguishes 2D and 3D items, keeping most of the implementation in base classes.

When the player interacts with the item, it is teleported away, and a corresponding image is added to the first available inventory slot. I used render targets to keep 3D objects visually distinct from 2D objects. 

I chose to make the four inventory slots viewable but small at the bottom of the window during gameplay so that the player could see where the items go when picked up. Still, when opening the inventory, they grow and become interactable.

Instead of making the viewport window part of the widget, I use the player's camera to place the objects directly in front of the player, still inside the game world.

### Testing
Walk up to an item and the text "E - Pickup" willi appear. Press "E" to pick it up. 

Press "Tab" or "I" to open the inventory. You can use "Tab", "I", or "Escape" to exit the inventory, along with the close button in the top left.

While in the inventory, you can click and drag an item into one of the four slots. 

Drag and drop to an empty slot to move the item there.
If you drag and drop into a filled slot, the item will return to the starting slot.
Drag and drop anywhere that isn't one of the inventory slots to place the item in the viewport.

#### 2D Items:
"Forget note" button is in the top left, under the close button. It will remove the note from the inventory and not place it back into the world.
		
Press "Escape" or the close button to exit the viewport and return to the inventory. Press "I" to exit inventory completely
	
#### 3D Items:
3D items can be rotated while holding left click and moving the mouse.
They can be moved using WASD.
You can zoom the camera using the scroll wheel on the mouse.
		
Press "Escape" or the close button to exit the viewport and return to the inventory. Press "I" to exit inventory completely
		
## Dialogue system
### Design
For the dialogue, I used the same interactable class as the items as the base class.

Each dialogue actor has a text widget displayed once the player interacts with them. The text script is saved in a string array on the actor; I thought the dialogue could be read from external files (CSV, etc.) in the future.

The text gets printed into the UI a character at a time on a small timer unless the player chooses to skip forward, which will immediately print the complete line of text. Once all of the text is displayed, it waits for the player to click the "Next" button to start the following line of text.

Once the text has been printed, the button will close the text box and allow the player to start moving around the world again.

### Testing
When the player approaches the dialogue actor, the text "E - Talk" will appear. Press "E" to interact.

Once pressed the text box will open. In the bottom right corner it will say "Skip" while the text is printing. Hitting this button or pressed "E" key again will immediately finish the line of text.

Once the line is fully printed the button with read "Next". Pressed it or the "E" key to move to the next line.

When the final line is finished the button will change to "Close" this will exit the player from the conversation when pressed or hitting the "E" key.
