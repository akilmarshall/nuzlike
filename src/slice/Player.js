import { createSlice } from '@reduxjs/toolkit'


export const playerSlice = createSlice({
    name: 'player',
    initialState: {
        party: [0, 0, 0, 0, 0, 99],
        money: 100,
        starterPokemon: [252, 255, 258],
    },
    reducers: {
        addToParty: (state, pkmn) => {
            if (partyFull(state)) {
                const i = freePosition(state)
                state.party[i] = pkmn.payload
            }
        },
    }
})

function partyFull(state) {
    // return true if the party has no free positions
    for (let i = 0; i < 6; i++) {
        if (state.party[i] > 0) {
            return true 
        }
    }
    return false
}

function freePosition(state) {
    // return the first free position or nothing
    for (let i = 0; i < 6; i++) {
        if (state.party[i] === 0) {
            return i 
        }
    }
}

export const { addToParty } = playerSlice.actions
export default playerSlice.reducer
