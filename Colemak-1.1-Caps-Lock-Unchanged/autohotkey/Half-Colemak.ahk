#SingleInstance force
#NoEnv ; Recommended for performance and compatibility with future AutoHotkey releases.
SendMode Input ; Recommended for new scripts due to its superior speed and reliability.
SetTitleMatchMode 3  ; Exact matching to avoid confusing T/B with Tab/Backspace.

; Adapted from http://www.autohotkey.com/forum/viewtopic.php?t=1326
; Adaption to the Colemak layout: Shai Coleman, 2006-07-25

; Many thanks to Chris for helping me out with this script.
; Capslock hacks and `~ remap to '" by Watcher

mirror_1 = 0
mirror_2 = 9
mirror_3 = 8
mirror_4 = 7
mirror_5 = 6
mirror_6 = 5
mirror_7 = 4
mirror_8 = 3
mirror_9 = 2
mirror_0 = 1

mirror_q = `;
mirror_w = y
mirror_f = u
mirror_p = l
mirror_g = j
mirror_j = g
mirror_l = p
mirror_u = f
mirror_y = w

mirror_a = o
mirror_r = i
mirror_s = e
mirror_t = n
mirror_d = h
mirror_h = d
mirror_n = t
mirror_e = s
mirror_i = r
mirror_o = a

mirror_z = /
mirror_x = .
mirror_c = ,
mirror_v = m
mirror_b = k
mirror_k = b
mirror_m = v
return

; This key may help, as the space-on-up may get annoying, especially if you type fast.
Control & Space::Suspend

; Not exactly mirror but as close as we can get, Capslock enter, Tab backspace.
Space & CapsLock::Send {Enter}
Space & Tab::Send {Backspace}
Space & '::Send {Backspace}

; Without this capslock would shift only letters, this resolves that issue.
+CapsLock::   ; Must catch capslock and Shift capslock to make this work.
CapsLock::
  if CapsState = D
  {
    CapsState = U
    Send {LShift Up}
  }
  else
  {
    CapsState = D
    Send {LShift Down}
  }
  return

Shift::CapsState = U  ; User pressed shift which toggles shift back up.
; The only strange part of this setup is that although capslock will toggle
; shift state, hitting the shift key will not toggle, it will act as a shift
; key reguardless of the capslock state and release afterward.


; If spacebar didn't modify anything, send a real space keystroke upon release.
space::
Send {space}
return

space & `::
space & 1::
space & 2::
space & 3::
space & 4::
space & 5::
space & 6::
space & 7::
space & 8::
space & 9::
space & 0::

space & q::
space & w::
space & f::
space & p::
space & g::
space & j::
space & l::
space & u::
space & y::
space & `;::

space & a::
space & r::
space & s::
space & t::
space & d::
space & h::
space & n::
space & e::
space & i::
space & o::

space & z::
space & x::
space & c::
space & v::
space & b::
space & k::
space & m::
space & ,::
space & .::
space & /::

; Determine the mirror key, if there is one:
if A_ThisHotkey = space & ``
   MirrorKey = '
else if A_ThisHotkey = space & `;
   MirrorKey = q
else if A_ThisHotkey = space & ,
   MirrorKey = c
else if A_ThisHotkey = space & .
   MirrorKey = x
else if A_ThisHotkey = space & /
   MirrorKey = z
else  ; To avoid runtime errors due to invalid var names, do this part last.
{
   StringRight, ThisKey, A_ThisHotkey, 1
   StringTrimRight, MirrorKey, mirror_%ThisKey%, 0  ; Retrieve "array" element.
   if MirrorKey =  ; No mirror, script probably needs adjustment.
      return
}

Modifiers =
GetKeyState, state1, LWin
GetKeyState, state2, RWin
state = %state1%%state2%
if state <> UU  ; At least one Windows key is down.
   Modifiers = %Modifiers%#
GetKeyState, state1, Control
if state1 = D
   Modifiers = %Modifiers%^
GetKeyState, state1, Alt
if state1 = D
   Modifiers = %Modifiers%!
GetKeyState, state1, Shift
if state1 = D
   Modifiers = %Modifiers%+
Send %Modifiers%{%MirrorKey%}
return 
