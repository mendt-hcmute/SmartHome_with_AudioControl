from PIL import Image
import numpy as np
import os

def rgb888_to_rgb565(r, g, b):
    """Chuyển đổi RGB888 thành RGB565"""
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)

# Đọc và thay đổi kích thước ảnh
image_path = "img/high-temperature.png"  # Đặt đường dẫn đến ảnh của bạn
img = Image.open(image_path)
img = img.resize((50, 50))  # Thay đổi kích thước ảnh để phù hợp với màn hình TFT

# Lưu ảnh sau khi resize vào thư mục 'converted_img'
output_folder = 'converted_img'
if not os.path.exists(output_folder):
    os.makedirs(output_folder)

# Lưu ảnh đã thay đổi kích thước vào thư mục 'converted_img'
output_image_path = os.path.join(output_folder, 'high-temperature.png')
img.save(output_image_path)

# Chuyển ảnh thành mảng RGB
img = img.convert('RGB')
img_array = np.array(img)

# Tạo mảng lưu bitmap 16-bit
bitmap = []
for row in img_array:
    for pixel in row:
        r, g, b = pixel
        rgb565 = rgb888_to_rgb565(r, g, b)
        bitmap.append(rgb565)

# Chuyển mảng thành định dạng C++
bitmap_str = ', '.join([f"0x{val:04X}" for val in bitmap])

# In ra mảng bitmap dưới dạng C++ array
print(f"const uint16_t image[] PROGMEM = {{\n  {bitmap_str}\n}};")

print(f"Ảnh đã được lưu tại: {output_image_path}")
