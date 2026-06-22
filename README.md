# EEG-BCI-single-channel
Scalp (µV-level biopotential signal)
           │
           │  AgCl electrodes (A1, A2 active — earlobes; Fpz reference)
           │  Conductive gel applied for impedance reduction
           ▼
┌─────────────────────┐
│   Protection Stage  │  Series resistors + low-leakage diodes
│                     │  Limits input current to AD620AN inputs
│                     │  Prevents damage from ESD or patient movement
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│     AD620AN         │  Instrumentation Amplifier
│                     │  Gain:  G = (49.4 kΩ / Rg) + 1
│  CMRR > 100 dB      │  Rg = 500 kΩ → G ≈ 1.1× (pre-amp stage)
│                     │  Rejects common-mode noise on both electrodes
│                     │  Differential input → single-ended output
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│     TL074           │  Quad Op-Amp — Post-Amplifier + Filter Driver
│                     │  Post-amp gain: Gb = 1 + (Rf / R1)
│                     │  Additional voltage gain stage
│                     │  Drives passive filter network
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  2nd-Order Passive  │  Bandpass Filter
│  Bandpass Filter    │  Cutoff: Fc = 1 / (2π × √(R1 × R2 × C1 × C2))
│  0.5 Hz – 50 Hz    │  Passes: delta, theta, alpha, beta, low-gamma
│                     │  Rejects: DC drift, electrode offset, HF noise
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Twin-T Notch       │  50 Hz Powerline Rejection Filter
│  Filter — 50 Hz     │  Eliminates Indian grid frequency interference
│                     │  Passive RC Twin-T topology
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Bias Network       │  DC Offset Correction (Phase 2 addition)
│  2 × 10 kΩ          │  Voltage divider: 3.3 V rail → ~1.65 V midpoint
│  → ~1.65 V offset   │  Shifts bipolar TL074 output into ESP32 ADC range
│                     │  Required because ESP32 ADC accepts only 0–3.3 V
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│     ESP32           │  12-bit SAR ADC
│     GPIO 34         │  Resolution: 4096 steps over 0–3.3 V
│     ~100 Hz         │  Sampling: 10 ms delay loop ≈ 100 Hz effective
│     115200 baud     │  Output: raw ADC counts via USB serial
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Python Pipeline    │  PC-side signal processing
│  pyserial           │  Serial read from ESP32
│  NumPy FFT          │  Spectral analysis (FFT-based PSD)
│  pyqtgraph          │  Real-time waveform and FFT visualisation
└─────────────────────┘
