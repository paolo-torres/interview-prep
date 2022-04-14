// Oxygen, hydrogen, group to form molecules at barrier, write code to enforce:
// (1) If O arrives w/ no H present, must wait for 2 H
// (2) If H arrives w/ no O or H present, must wait for 1 O and 1 H

// If pairing is false, not enough resources to start, wait, ex. HOOO or HHHH
// If pairing is true, have resources, signal to other threads this has started

// Time: O(n)
// Space: O(1)

class H2O {
public:
    H2O() {
        h = 0;
        o = 0;
        reset();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        // single mutex since doing reads on unsynced variable
        unique_lock<mutex> ul(m);
        h++;
        // waits until begins bonding/has resources
        hCv.wait(ul, [&]() {
            return (isBonding && hRemaining > 0) || (!isBonding && h >= 2 && o >= 1);
        });
        
        // if 1st thread started bonding, mark process as started
        isBonding = true;
        hRemaining--;
        h--;
        
        // if need more hydrogen
        if (hRemaining > 0) {
            hCv.notify_one();
        }
        
        // if need more oxygen
        if (oRemaining > 0) {
            oCv.notify_one();
        }
        
        // done bonding
        if (hRemaining == 0 && oRemaining == 0) {
            reset();
        }
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> ul(m);
        o++;
        oCv.wait(ul, [&]() {
            return (isBonding && oRemaining > 0) || (!isBonding && h >= 2 && o >= 1);
        });
        
        // if 1st thread started bonding, mark process as started
        isBonding = true;
        oRemaining--;
        o--;
        
        // if need more hydrogen
        if (hRemaining == 1) {
            hCv.notify_one();
        } else if (hRemaining == 2) {
            hCv.notify_all();
        }
        
        // done bonding
        if (hRemaining == 0 && oRemaining == 0) {
            reset();
        }
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
    }
private:
    // # of threads waiting
    int h;
    int o;
    // how many more H's and O's left
    int hRemaining;
    int oRemaining;
    // if pairing has started
    bool isBonding;
    
    mutex m;
    condition_variable hCv;
    condition_variable oCv;
    
    // called when molecules are done bonding
    void reset() {
        hRemaining = 2;
        oRemaining = 1;
        isBonding = false;
    }
};
