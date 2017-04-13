function y=OutputOfChannel(x,channel_state)
%
%   USAGE:
%       y=OutputOfChannel(x,channel_string,channel_state)
%
% Given a binary "x" (matrix/vector), simulates a channel
% specified by "channel_string" == 'BSC' or 'BEC' or 'AWGN';
% modulates if necessary, adds noise and returns the output.
% Modulation is assumed BPSK, by-default, only for AWGN channel.
%
%   The "channel_state" is :
%       Ec/N0 -aka- SNR when channel_string=='AWGN'
%

global PCparams;
channel_state = PCparams.design_channelstate;
% Assume the NORMALIZATION:
%     N0/2, the noise-variance is assumed to be unity.
% BPSK: 0 -> +sqrt(R*Eb/N0);  1 -> -sqrt(R*Eb/N0)

sqrtEcN0 = sqrt(PCparams.K/PCparams.N) * 10^(channel_state/20);
y = (2*x-1)*sqrtEcN0*sqrt(2) + randn(size(x)); %AWGN with normalization

