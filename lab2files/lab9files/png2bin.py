#import sys #/path/to/python/used/by/vs/code/python -m pip install pillow
#print(sys.executable)

from PIL import Image, ImageEnhance

def write_image(image, filename):
    height = image.height
    width = image.width
    
    with open(filename, "wb") as f:
        f.write(height.to_bytes(2, byteorder='big'))
        f.write(width.to_bytes(2, byteorder='big'))
        img_raster = []
        for i in range(height):
            for j in range(width):
                img_raster.extend(image.getpixel((j, i))[:3])
        f.write(bytearray(img_raster))

def read_2bytes(f):
    return int.from_bytes(f.read(2), byteorder='big')

def read_image(filename):
    try:
        with open(filename, "rb") as f:
            print(f"Successfully opened {filename}")
            height = read_2bytes(f)
            width = read_2bytes(f)
            image = Image.new("RGB", (width, height))
            bytes = f.read()
            for i in range(height):
                for j in range(width):
                    image.putpixel((j, i), (bytes[3*(i*width + j)+0],
                                            bytes[3*(i*width + j)+1],
                                            bytes[3*(i*width + j)+2]))
            return image
    except FileNotFoundError:
        print(f"Error: {filename} not found!")
    except Exception as e:
        print(f"Unexpected error: {e}")

def adjust_brightness(img, factor):
    enhancer = ImageEnhance.Brightness(img)
    return enhancer.enhance(factor)

def create_gif(bin_image_path, output_gif):
    img = read_image(bin_image_path)
    factors = [0.5, 0.75, 1.0, 1.25, 1.5]
    frames = [adjust_brightness(img, f) for f in factors]
    frames[0].save(output_gif, save_all=True, append_images=frames[1:], duration=300, loop=0)

if __name__ == '__main__':
    create_gif("bright3.bin", "brightness.gif")
