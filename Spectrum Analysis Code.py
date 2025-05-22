import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft, fftfreq
import pandas as pd

# Load data
data = pd.read_csv("data_corrected.csv", names=["mV", "digital"])
analog = data["mV"].values
digital = data["digital"].values

# Sampling info
Fs = 10  # Hz
N = len(analog)
T = 1.0 / Fs
time = np.arange(N) * T

# FFT computation
analog_fft = fft(analog)
digital_fft = fft(digital)
freqs = fftfreq(N, T)

# Only positive frequencies
pos_mask = freqs >= 0
freqs = freqs[pos_mask]
analog_fft_mag = np.abs(analog_fft[pos_mask]) / N
digital_fft_mag = np.abs(digital_fft[pos_mask]) / N

# Convert to dB scale for better spectral view
analog_db = 20 * np.log10(analog_fft_mag + 1e-6)  # avoid log(0)
digital_db = 20 * np.log10(digital_fft_mag + 1e-6)

# Plotting
plt.figure(figsize=(12, 10))

# 1. Analog Time Domain
plt.subplot(2, 2, 1)
plt.plot(time, analog, color='blue')
plt.title("Analog Signal (Time Domain)")
plt.xlabel("Time [s]")
plt.ylabel("Voltage [mV]")
plt.grid(True)

# 2. Digital Time Domain
plt.subplot(2, 2, 2)
plt.plot(time, digital, color='orange', linestyle='--')
plt.title("Digital Signal (Time Domain)")
plt.xlabel("Time [s]")
plt.ylabel("8-bit Value")
plt.grid(True)

# 3. Analog Spectrum
plt.subplot(2, 2, 3)
plt.plot(freqs, analog_db, color='blue')
plt.title("Analog Spectrum (FFT, dB)")
plt.xlabel("Frequency [Hz]")
plt.ylabel("Magnitude [dB]")
plt.grid(True)

# 4. Digital Spectrum
plt.subplot(2, 2, 4)
plt.plot(freqs, digital_db, color='orange', linestyle='--')
plt.title("Digital Spectrum (FFT, dB)")
plt.xlabel("Frequency [Hz]")
plt.ylabel("Magnitude [dB]")
plt.grid(True)

plt.tight_layout()
plt.show()
