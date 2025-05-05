# ====================================
# 📚 Import Required Modules
# ====================================
from PIL import Image, ImageEnhance
import os

# ====================================
# 🎨 Function to Create Lighter Frames
# ====================================
def create_lighter_frames(image, frame_dir, num_frames=10, min_brightness=1.0, max_brightness=2.5):
    """
    Generate frames with progressively increasing brightness.
    
    Parameters:
    - image: PIL image to enhance
    - frame_dir: Directory to save frames
    - num_frames: Number of frames to generate
    - min_brightness: Starting brightness factor
    - max_brightness: Maximum brightness factor
    """
    enhancer = ImageEnhance.Brightness(image)
    
    for i in range(num_frames):
        # Scale brightness progressively
        factor = min_brightness + (max_brightness - min_brightness) * (i / (num_frames - 1))

        # Enhance brightness and create frame
        frame = enhancer.enhance(factor)
        frame_name = os.path.join(frame_dir, f"frame_{i+1:03d}.jpg")
        
        # Save the frame
        frame.save(frame_name)
    
    print(f"✅ Frames saved successfully in '{frame_dir}'!")

# ====================================
# 🎥 Function to Create GIF
# ====================================
def create_gif_from_frames(frame_dir, output_gif, duration=100):
    """
    Create a GIF from a series of frames.
    
    Parameters:
    - frame_dir: Directory where frames are stored
    - output_gif: Name of the output GIF
    - duration: Duration per frame in milliseconds
    """
    # Get all frame filenames and sort them to maintain order
    frame_files = sorted([os.path.join(frame_dir, f) for f in os.listdir(frame_dir) if f.endswith(".jpg")])

    # Load frames into a list
    frames = [Image.open(frame_file) for frame_file in frame_files]

    # Save frames as a GIF
    if frames:
        frames[0].save(
            output_gif,
            save_all=True,
            append_images=frames[1:],
            duration=duration,  # Time per frame in milliseconds
            loop=0  # Infinite loop
        )
        print(f"🎉 GIF created successfully and saved as '{output_gif}'!")
    else:
        print("⚠️ No frames found. Check if frame generation was successful.")

# ====================================
# 📂 Main Code to Run Everything
# ====================================
# Input your JPG file name here
input_image_path = "/Users/saraparvaresh/Library/Mobile Documents/com~apple~CloudDocs/uni resources/1W/esc190/C/labs/lab9files/cannon.jpg"  # Update this with your image filename

# Output directories and filenames
frame_dir = "lighter_frames"
output_gif = "lighter_animation.gif"

# Create output directory if it doesn't exist
os.makedirs(frame_dir, exist_ok=True)

# ============================
# 📸 Open the Original Image
# ============================
try:
    original_image = Image.open(input_image_path)
    print(f"📸 Successfully opened '{input_image_path}'!")
except FileNotFoundError:
    print(f"❌ Error: '{input_image_path}' not found. Check the file path.")
    exit()

# ============================
# 🌞 Generate Lighter Frames
# ============================
create_lighter_frames(original_image, frame_dir)

# ============================
# 🎥 Create GIF from Frames
# ============================
create_gif_from_frames(frame_dir, output_gif)

# ============================
# 📂 Verify GIF Creation
# ============================
if os.path.exists(output_gif):
    print(f"✅ GIF successfully saved at: {os.path.abspath(output_gif)}")

    # ============================
    # 🎉 Open and Display the GIF
    # ============================
    gif_image = Image.open(output_gif)
    gif_image.show()
else:
    print("❌ Error: GIF was not saved.")