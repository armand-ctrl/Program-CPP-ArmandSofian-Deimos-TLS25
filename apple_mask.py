import cv2
import numpy as np
import sys

def create_apple_mask(input_image_path, output_image_path):
    """
    Membuat binary mask dari gambar apel.
    Apel akan berwarna putih (255), background dan bayangan hitam (0).
    """
    # Baca gambar
    image = cv2.imread(input_image_path)
    if image is None:
        print(f"Error: Tidak dapat membaca gambar dari {input_image_path}")
        return False
    
    # Konversi ke HSV color space untuk deteksi warna lebih baik
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    
    # Define range untuk warna merah apel
    # Merah memiliki dua range di HSV (karena wrapping di 0/180)
    # Range 1: Merah gelap/tua
    lower_red1 = np.array([0, 50, 50])
    upper_red1 = np.array([10, 255, 255])
    
    # Range 2: Merah terang
    lower_red2 = np.array([170, 50, 50])
    upper_red2 = np.array([180, 255, 255])
    
    # Buat mask untuk kedua range merah
    mask1 = cv2.inRange(hsv, lower_red1, upper_red1)
    mask2 = cv2.inRange(hsv, lower_red2, upper_red2)
    
    # Gabungkan kedua mask
    red_mask = cv2.bitwise_or(mask1, mask2)
    
    # Tambahkan deteksi untuk area yang lebih gelap (bayangan apel)
    # Gunakan threshold pada brightness
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    
    # Deteksi area dengan brightness sedang-tinggi (bukan bayangan)
    _, bright_mask = cv2.threshold(gray, 30, 255, cv2.THRESH_BINARY)
    
    # Kombinasikan red mask dengan bright mask
    combined_mask = cv2.bitwise_and(red_mask, bright_mask)
    
    # Morphological operations untuk membersihkan noise
    kernel = np.ones((5, 5), np.uint8)
    
    # Closing: menghilangkan lubang kecil di dalam objek
    combined_mask = cv2.morphologyEx(combined_mask, cv2.MORPH_CLOSE, kernel, iterations=3)
    
    # Opening: menghilangkan noise kecil di luar objek
    combined_mask = cv2.morphologyEx(combined_mask, cv2.MORPH_OPEN, kernel, iterations=2)
    
    # Dilate untuk mengisi area yang mungkin terlewat
    combined_mask = cv2.dilate(combined_mask, kernel, iterations=2)
    
    # Find contours dan ambil yang terbesar (apel)
    contours, _ = cv2.findContours(combined_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    if contours:
        # Buat mask kosong
        final_mask = np.zeros_like(gray)
        
        # Ambil contour terbesar (asumsi: apel adalah objek terbesar)
        largest_contour = max(contours, key=cv2.contourArea)
        
        # Fill contour terbesar dengan putih
        cv2.drawContours(final_mask, [largest_contour], -1, 255, -1)
        
        # Simpan hasil
        cv2.imwrite(output_image_path, final_mask)
        print(f"Binary mask berhasil disimpan ke {output_image_path}")
        return True
    else:
        print("Error: Tidak dapat mendeteksi apel dalam gambar")
        return False

def main():
    if len(sys.argv) < 2:
        print("Usage: python apple_mask.py <input_image_path> [output_image_path]")
        print("Example: python apple_mask.py input.jpg output.png")
        return
    
    input_path = sys.argv[1]
    output_path = sys.argv[2] if len(sys.argv) > 2 else "apple_mask_output.png"
    
    create_apple_mask(input_path, output_path)

if __name__ == "__main__":
    main()
