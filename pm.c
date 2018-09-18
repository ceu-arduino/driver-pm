#define CEU_PM_ON(dev) ((int)(ceu_pm_state[dev] > 0))

#ifdef __cplusplus
extern "C" {
#endif

static u8 ceu_pm_state[CEU_PM_N];

void ceu_pm_init (void);

void _ceu_pm_init (void) {
    memset(ceu_pm_state, 0, CEU_PM_N * sizeof(u8));
}

void ceu_pm_sleep (void);

void ceu_pm_inc (u8 dev, bool inc) {
    //ceu_assert(inc==-1 && ceu_pm_state[dev]>0 ||
               //inc== 1 && ceu_pm_state[dev]<U8_MAX, "bug found");
    ceu_pm_state[dev] += inc;
}

#ifdef __cplusplus
}
#endif
