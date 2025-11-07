# Apple Binary Mask Generator

Program untuk menghasilkan binary mask dari gambar apel.

## Deskripsi
Program ini menerima input gambar yang berisi apel dan menghasilkan binary mask di mana:
- **Putih (255)**: Area apel
- **Hitam (0)**: Background, bayangan, dan objek lainnya

## Teknologi
- Python 3
- OpenCV (cv2)
- NumPy

## Instalasi Dependencies

```bash
pip install opencv-python numpy
```

## Cara Penggunaan

### Format Dasar
```bash
python apple_mask.py <input_image_path> [output_image_path]
```

### Contoh Penggunaan
```bash
# Dengan output path custom
python apple_mask.py uploads/Screenshot\ 2025-11-07\ 183710.png apple_output.png

# Output default (apple_mask_output.png)
python apple_mask.py input.jpg
```

## Cara Kerja Program

1. **Membaca Gambar**: Program membaca gambar input menggunakan OpenCV
2. **Konversi Color Space**: Mengkonversi dari BGR ke HSV untuk deteksi warna yang lebih akurat
3. **Deteksi Warna Merah**: Menggunakan dua range HSV untuk mendeteksi warna merah apel
4. **Filter Brightness**: Menghilangkan bayangan dengan threshold brightness
5. **Morphological Operations**: 
   - Closing: Mengisi lubang kecil dalam objek
   - Opening: Menghilangkan noise kecil
   - Dilation: Memperluas area untuk mengisi gap
6. **Contour Detection**: Menemukan kontur dan memilih yang terbesar (apel)
7. **Generate Mask**: Membuat binary mask final dengan apel berwarna putih

## Output
Program akan menghasilkan file gambar binary mask dengan format:
- Apel: Putih (nilai pixel 255)
- Background & Bayangan: Hitam (nilai pixel 0)

## Catatan
- Program mengasumsikan apel adalah objek terbesar dalam gambar
- Bekerja optimal untuk apel berwarna merah
- Format output: PNG (recommended untuk binary mask)
