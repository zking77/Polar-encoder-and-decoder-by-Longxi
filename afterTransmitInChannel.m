function y=afterTransmitInChannel(x)
%   USAGE:
%       y=OutputOfChannel(x,channel_string,channel_state)
%
% Given a binary "x" (matrix/vector), simulates a channel
% specified by "channel_string" == 'AWGN';
% modulates if necessary, adds noise and returns the output.
% Modulation is assumed BPSK, by-default, for AWGN channel.
%
%   The "channel_state" is :
%       Ec/N0 -aka- SNR when channel_string=='AWGN'
%   SNR (Default: 0dB;  := Eb/N0,  where (K*Eb/N) is the energy used during BPSK modulation of coded-bits
% Assume the NORMALIZATION:
%     N0/2, the noise-variance is assumed to be unity.
% BPSK: 0 -> +sqrt(R*Eb/N0);  1 -> -sqrt(R*Eb/N0)
global PCparams;
channel_state = PCparams.design_channelstate;
sqrtEcN0 = sqrt(PCparams.K/PCparams.N) * 10^(channel_state/10/2);  %由SNR=10log下标10（N/K*Ec/N0）推导得到；N0/2是归一化的标准。
y = (2*x-1)*sqrtEcN0*sqrt(2) + randn(size(x)); %AWGN with normalization

