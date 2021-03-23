(function(exports) {
    // var oscillator = null;
    // var isPlaying = false;

    function PwmSpeaker(pins) {
        exports.BaseComponent.call(this);
        audioCtx = new (window.AudioContext || window.webkitAudioContext)();

        this.dataPin = pins.Speaker;
        this.oscillator = null;
        this.isPlaying = false;
        this.volume_value = 0;
        this.frequency = 10;
        this.componentsEl = document.querySelector('#components');
        this._on_pin_period= this.on_pin_period.bind(this);
        this._on_pin_write = this.on_pin_write.bind(this);

    }

    PwmSpeaker.prototype = Object.create(exports.BaseComponent.prototype);

    PwmSpeaker.prototype.init = function() {
        window.MbedJSHal.gpio.on('pin_period', this._on_pin_period);
        window.MbedJSHal.gpio.on('pin_write', this._on_pin_write);

        var el = this._el = document.createElement('div');
        el.classList.add('component');
        el.classList.add('PwmSpeaker');
        var p = document.createElement('p');
        p.classList.add('description');

        p.textContent = 'PWM Speaker (' + this.pinNameForPin(this.dataPin) + ')';

        p.appendChild(this.createDestroyEl());
        el.appendChild(p);

        var img = document.createElement('img');
        img.src = '/img/' + 'pwm_speaker.png';
        img.style.width = '100px';
        el.appendChild(img);

        // var synth = new Tone.Synth().toMaster();

       
        this.componentsEl.appendChild(el);  


        // synth.triggerAttackRelease('C4', '8n');
        

        this._on_pin_write(this.dataPin, MbedJSHal.gpio.read(this.dataPin), MbedJSHal.gpio.get_type(this.dataPin));
        this._on_pin_period(this.dataPin, MbedJSHal.gpio.get_period_us(this.dataPin));

    };

    PwmSpeaker.prototype.destroy = function() {
        window.MbedJSHal.gpio.removeListener('pin_write', this._on_pin_write);
        window.MbedJSHal.gpio.removeListener('pin_period', this._on_pin_period);
        this.oscillator.stop();
        this.isPlaying = false;

        window.removeComponent(this);

        this.componentsEl.removeChild(this._el);

    };

    PwmSpeaker.prototype.on_pin_write = function(pin, value, type) {
        if (pin !== this.dataPin) return;

        if (type == MbedJSHal.gpio.TYPE.PWM) {
            this.volume_value = value/1024;
            this.play();
        }
    };

    PwmSpeaker.prototype.on_pin_period = function (pin, period){
        if (pin !== this.dataPin) return;

        if (MbedJSHal.gpio.get_type(pin) == MbedJSHal.gpio.TYPE.PWM) {
            this.frequency = 1/period*1000000;
            this.play();
        }
    }

    PwmSpeaker.prototype.play = function (){
        if(this.isPlaying == true) {// checking if the speaker was playing before 
            this.oscillator.stop();
            this.isPlaying = false;
        }

        var Volume = audioCtx.createGain();
        Volume.connect(audioCtx.destination);
        Volume.gain.value= this.volume_value;

        var Oscillator = audioCtx.createOscillator();
        Oscillator.type = 'square';
        Oscillator.frequency.value = this.frequency; // value in hertz
        
        Oscillator.connect(Volume);
        
        Oscillator.start();
        this.oscillator=Oscillator;
        this.isPlaying = true;
    };

    exports.PwmSpeaker = PwmSpeaker;
})(window.MbedJSUI);
